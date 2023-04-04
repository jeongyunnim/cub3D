/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:33:26 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/04 18:39:10 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_two_dimension_array(void **arr)
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

static int	init_rgb(t_info *info, char **type)
{
	char	**rgb;
	int		error_flag;

	error_flag = 0;
	rgb = ft_split(type[1], ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		error_flag = 1;
	else if (strncmp(type[0], "F", 2) == 0 && FLOOR & info->flag == 0)
	{
		info->flag |= FLOOR;
		info->floor[0] = ft_atoi(rgb[0]);
		info->floor[1] = ft_atoi(rgb[1]);
		info->floor[2] = ft_atoi(rgb[2]);
	}
	else if (strncmp(type[0], "C", 2) == 0 && CEILING & info->flag == 0)
	{
		info->flag |= CEILING;
		info->ceiling[0] = ft_atoi(rgb[0]);
		info->ceiling[1] = ft_atoi(rgb[1]);
		info->ceiling[2] = ft_atoi(rgb[2]);
	}
	else
		error_flag = 1;
	free_two_dimension_array(rgb);
	return (error_flag);
}

static int	type_init(t_info *info, char **type)
{
	if (strncmp(type[0], "NO", 3) == 0 && NORTH & info->flag == 0)
	{
		info->flag |= NORTH;
		info->north = ft_strdup(type[1]);
	}
	else if (strncmp(type[0], "SO", 3) == 0 && SOUTH & info->flag == 0)
	{
		info->flag |= SOUTH;
		info->south = ft_strdup(type[1]);
	}
	else if (strncmp(type[0], "WE", 3) == 0 && WEST & info->flag == 0)
	{
		info->flag |= WEST;
		info->west = ft_strdup(type[1]);
	}
	else if (strncmp(type[0], "EA", 3) == 0 && EAST & info->flag == 0)
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
		if (line == NULL || (NORTH | SOUTH | WEST | EAST | FLOOR | CEILING))
			break ;
		type_temp = split_is_function(line, ft_isspace);
		if (type_temp[0] == NULL)
		{
			free_two_dimension_array(type_temp);
			continue ;
		}
		if (type_temp[1] != NULL && type_temp[2] == NULL)
		{
			if (type_init(info, type_temp) == ERROR)
			{
				ft_putstr_fd("Error\nInvalid type information form\n", 2);
				free_two_dimension_array(type_temp);
				return (ERROR);
			}
		}
		else
		{
			ft_putstr_fd("Error\nInvalid type information form\n", 2);
			free_two_dimension_array(type_temp);
			return (ERROR);
		}
		free_two_dimension_array(type_temp);
	}
	return (1);
}
