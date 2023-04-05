/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:03:16 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/05 20:48:43 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*jump_to_map(t_info *info, int fd)
{
	char	*line;
	int		i;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == ' ' || line[i] == '1' || line[i] == '\n')
			{
				if (line[i] == '1')
					return (line);
			}
			else
			{
				free(line);
				return (NULL);
			}
			i++;
		}
		free(line);
	}
	return (NULL);
}

int	map_parse(t_info *info, int fd)
{
	char	*line;

	line = jump_to_map(info, fd);
	if (line == NULL)
	{
		ft_putstr_fd("Error\nIncompleted map error\n");
		return (ERROR);
	}
	//오른손 법칙 알고리즘
	return (0);
}
