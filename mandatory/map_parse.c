/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:03:16 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 21:24:57 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parse(t_info *info, int fd, char *first_line)
{
	t_map_list	head;
	t_map_info	map_info;
	char		*line;

	head.next = NULL;
	add_map_line_tail(&head, lstnew_map_line(first_line));
	free(first_line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_map_line_tail(&head, lstnew_map_line(line));
		free(line);
	}
	if (check_all_line(&map_info, head.next) == ERROR)
	{
		free_map_list(head.next);
		return (put_error(info, "Error\nInvalid map component\n"));
	}
	define_map_size(info, &map_info, head.next);
	free_map_list(head.next);
	if (check_closed_map(info) == ERROR)
		return (put_error(info, "Error\nMap is not closed\n"));
	return (0);
}
