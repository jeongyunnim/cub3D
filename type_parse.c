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

int	type_parse(t_info *info, int fd)
{
	char	*line;
	char	**type_temp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		type_temp = ft_split(line, ft_isspace);
		if (type_temp[0] == NULL)
		{
			//freeall
			continue ;
		}
		if (type_temp[1] != NULL && type_temp[2] == NULL)
		{
			if (check_type_valid(type_temp[0]))
			{}
			else
			{
				//error
			}
		}
		else
		{
			//error
		}
	}
	return (1);
}
