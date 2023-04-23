/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:33:26 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/24 07:04:03 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (TYPE_S == info->flag)
			break ;
	}
	if (info->floor[0] == info->ceiling[0] && \
	info->floor[1] == info->ceiling[1] && info->floor[2] == info->ceiling[2])
		return (ERROR);
	return (0);
}
