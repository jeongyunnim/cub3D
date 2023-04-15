/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map_list_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:55:51 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/06 16:08:22 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_list	*lstnew_map_line(char *one_line)
{
	t_map_list	*link;

	link = (t_map_list *)ft_calloc(1, sizeof(t_map_list));
	link->one_line = ft_strdup(one_line);
	return (link);
}

t_map_list	*pop_map_line_head(t_map_list **head)
{
	t_map_list	*pop;

	pop = *head;
	if (pop == NULL)
		return (NULL);
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
	}
	else
	{
		*head = NULL;
	}
	pop->next = NULL;
	return (pop);
}

void	add_map_line_tail(t_map_list *head, t_map_list *new)
{
	t_map_list	*move_head;

	move_head = head;
	while (move_head->next != NULL)
	{
		move_head = move_head->next;
	}
	move_head->next = new;
}
