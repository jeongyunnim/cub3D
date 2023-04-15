/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:04 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/06 20:15:27 by jeseo            ###   ########.fr       */
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

int	parse(t_info *info, int fd)
{
	char	*line;

	if (type_parse(info, fd) == ERROR)
	{
		ft_putstr_fd("Error\nInvalid type information form\n", 2);
		return (ERROR);
	}
	line = jump_to_map(info, fd);
	if (line == NULL)
	{
		ft_putstr_fd("Error\nIncompleted map error\n", 2);
		return (ERROR);
	}
	if (map_parse(info, fd, line) == ERROR)
	{
		return (ERROR);
	}
	return (0);
}
