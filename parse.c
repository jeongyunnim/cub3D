/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:04 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/24 01:39:30 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_exit_wall(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '\n')
		{
			if (line[i] == '1')
				return (1);
		}
		else
		{
			free(line);
			return (0);
		}
		i++;
	}
	free(line);
	return (2);
}

char	*jump_to_map(int fd)
{
	char	*line;
	int		flag;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		flag = check_exit_wall(line);
		if (flag == 1)
			return (line);
		else if (flag == 2)
			continue ;
		else
			return (NULL);
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
	line = jump_to_map(fd);
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
