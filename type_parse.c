/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:33:26 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/18 16:25:27 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_two_dimension_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	rgb_valid_check(t_info *info, char **rgb, int target[3])
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (j == 0 && (rgb[i][j] == '-' || rgb[i][j] == '+'))
				j++;
			if (ft_isdigit(rgb[i][j]) == 0)
				return (ERROR);
			j++;
		}
		temp = ft_atoi(rgb[i]);
		if ((temp < 0 || 255 < temp))
			return (ERROR);
		target[i] = temp;
		i++;
	}
	return (0);
}

static int	init_rgb(t_info *info, char **type)
{
	char	**rgb;
	int		error_flag;
	int		comma_flag;
	int		i;

	error_flag = 0;
	comma_flag = 0;
	i = 0;
	while (type[1][i] != '\0')
	{
		if (ft_isdigit(type[1][i]) == 0 && type[1][i] != ',' && type[1][i] != '-' && type[1][i] != '+')
			return (ERROR);
		if (type[1][i] == ',')
			comma_flag++;
		i++;
	}
	if (comma_flag != 2)
		return (ERROR);
	rgb = ft_split(type[1], ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		error_flag = 1;
	else if (ft_strncmp(type[0], "F", 2) == 0 && (FLOOR & info->flag) == 0)
	{
		info->flag |= FLOOR;
		error_flag = rgb_valid_check(info, rgb, info->floor);
	}
	else if (ft_strncmp(type[0], "C", 2) == 0 && (CEILING & info->flag) == 0)
	{
		info->flag |= CEILING;
		error_flag = rgb_valid_check(info, rgb, info->ceiling);
	}
	else
		error_flag = 1;
	free_two_dimension_array(rgb);
	return (error_flag);
}

static int	type_init(t_info *info, char **type)
{
	if (ft_strncmp(type[0], "NO", 3) == 0 && (NORTH & info->flag) == 0)
	{
		info->flag |= NORTH;
		info->north = ft_strdup(type[1]);
	}
	else if (ft_strncmp(type[0], "SO", 3) == 0 && (SOUTH & info->flag) == 0)
	{
		info->flag |= SOUTH;
		info->south = ft_strdup(type[1]);
	}
	else if (ft_strncmp(type[0], "WE", 3) == 0 && (WEST & info->flag) == 0)
	{
		info->flag |= WEST;
		info->west = ft_strdup(type[1]);
	}
	else if (ft_strncmp(type[0], "EA", 3) == 0 && (EAST & info->flag) == 0)
	{
		info->flag |= EAST;
		info->east = ft_strdup(type[1]);
	}
	else
		return (init_rgb(info, type));
	return (0);
}

int	type_parse(t_info *info, int fd)
{
	char	*line;
	char	**type_temp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || TYPE_S == info->flag)
			break ;
		type_temp = split_is_function(line, ft_isspace);
		if (type_temp[0] == NULL)
		{
			free_two_dimension_array(type_temp);
			free(line);
			continue ;
		}
		if (type_temp[1] != NULL && type_temp[2] == NULL)
		{
			if (type_init(info, type_temp) == ERROR)
			{
				free_two_dimension_array(type_temp);
				free(line);
				return (ERROR);
			}
		}
		else
		{
			free_two_dimension_array(type_temp);
			free(line);
			return (ERROR);
		}
		free(line);
		free_two_dimension_array(type_temp);
	}
	if (line != NULL && TYPE_S == info->flag)
		free(line);
	printf ("info\n%s\n%s\n%s\n%s\n%d,%d,%d\n%d,%d,%d\n", info->north, info->south, info->west, info->east, info->floor[0],info->floor[1],info->floor[2], info->ceiling[0], info->ceiling[1], info->ceiling[2]);
	return (0);
}
