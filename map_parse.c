/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:03:16 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/06 17:08:21 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parse(t_info *info, int fd)
{
	t_map_list	head;
	char		*line;

	head.next = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_map_line_tail(&head, lstnew_map_line(line));
	}

	t_map_list *temp;
	temp = head.next;
	while (temp->next != NULL)
	{
		printf("%s", temp->one_line);
		temp = temp->next;
	}
	//오른손 법칙 알고리즘
	return (0);
}
