/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:33:26 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/01 22:00:44 by suhkim           ###   ########.fr       */
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

int	check_type_valid(char *type_name)
{
	if (strncmp(type_name, "NO", 3) == 0)
		return (1);
	else if (strncmp(type_name, "SO", 3) == 0)
		return (1);
	else if (strncmp(type_name, "WE", 3) == 0)
		return (1);
	else if (strncmp(type_name, "EA", 3) == 0)
		return (1);
	else if (strncmp(type_name, "F", 2) == 0)
		return (1);
	else if (strncmp(type_name, "C", 2) == 0)
		return (1);
	else
		return (0);
}

static int	init_rgb(t_info *info, char flag, char **type)
{
	char	**rgb;

	rgb = ft_split(type[1], ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
	{
		free_two_dimension_array(rgb);
		//Error 처리 해야 함.
		return (ERROR);
	}
	else if (flag == 'F')
	{
		info->floor[0] = ft_atoi(rgb[0]);
		info->floor[1] = ft_atoi(rgb[1]);
		info->floor[2] = ft_atoi(rgb[2]);
		//숫자인지, 0~255 값 이내인지 확인해야 함.
	}
	else
	{
		info->ceiling[0] = ft_atoi(rgb[0]);
		info->ceiling[1] = ft_atoi(rgb[1]);
		info->ceiling[2] = ft_atoi(rgb[2]);
		//숫자인지, 0~255 값 이내인지 확인해야 함.
	}
	free_two_dimension_array(rgb);
	free(type[1]);
	return (0);
}

static int	type_init(t_info *info, char **type)
{
	int	ret_flag;

	ret_flag = 0;
	if (strncmp(type[0], "NO", 3) == 0)
		info->north = type[1];
	else if (strncmp(type[0], "SO", 3) == 0)
		info->south = type[1];
	else if (strncmp(type[0], "WE", 3) == 0)
		info->west = type[1];
	else if (strncmp(type[0], "EA", 3) == 0)
		info->east = type[1];
	else if (strncmp(type[0], "F", 2) == 0)
		ret_flag = init_rgb(info, 'F', type);
	else
		ret_flag = init_rgb(info, 'C', type);
	free(type[0]);
	return (ret_flag);
}

int	type_parse(t_info *info, int fd)
{
	char	*line;
	char	**type_temp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		type_temp = split_is_function(line, ft_isspace);
		if (type_temp[0] == NULL)
		{
			free_two_dimension_array(type_temp);
			continue ;
		}
		if (type_temp[1] != NULL && type_temp[2] == NULL)
		{
			if (check_type_valid(type_temp[0]))
			{
				if (type_init(info, type_temp) == ERROR) 
				//어차피 어떤 type인지 체크를 해야하므로 type_init()으로 check_type_valid()을 대체하는 편이 좋아보인다.
					return (ERROR);
			}
			else
			{
				ft_putstr_fd("Error\nInvalid type identifier\n", 2);
				return (ERROR);
			}
		}
		else
		{
			ft_putstr_fd("Error\nInvalid type information form\n", 2);
			return (ERROR);
		}
	}
	return (1);
}
