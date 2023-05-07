/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:33:26 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/07 18:37:20 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	enough_arg_check_vaild(t_info *info, char **type_temp, char *line)
{
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
	return (0);
}

static int	overlap_check(t_info *info)
{
	if (ft_strncmp(info->north, info->south, ft_strlen(info->north) + 1) == 0 \
	|| ft_strncmp(info->north, info->west, ft_strlen(info->north) + 1) == 0 \
	|| ft_strncmp(info->north, info->east, ft_strlen(info->north) + 1) == 0)
	{
		printf("north");
		return (ERROR);
	}
	if (ft_strncmp(info->south, info->west, ft_strlen(info->south) + 1) == 0 \
	|| ft_strncmp(info->south, info->east, ft_strlen(info->south) + 1) == 0)
	{
		printf("south");
		return (ERROR);
	}
	if (ft_strncmp(info->east, info->west, ft_strlen(info->east) + 1) == 0)
	{
		printf("east");
		return (ERROR);
	}
	if (info->floor[0] == info->ceiling[0] && \
	info->floor[1] == info->ceiling[1] && info->floor[2] == info->ceiling[2])
		return (ERROR);
	return (0);
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
			free(line);
			continue ;
		}
		if (enough_arg_check_vaild(info, type_temp, line) == ERROR)
			return (ERROR);
		free_two_dimension_array(type_temp);
		if (TYPE_S == info->flag.type)
			break ;
	}
	if (overlap_check(info) == ERROR)
		return (ERROR);
	return (0);
}
