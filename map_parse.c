/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:03:16 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/06 18:25:48 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_one_line(char *line, t_map_info *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (map->height == 0)
		map->min_w = ft_strchr(line, '1') - line;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != '\n' && \
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (ERROR);
		if (line[i] == '1')
		{
			if (i < map->min_w)
				map->min_w = i;
			if (i > map->max_w)
				map->max_w = i;
			flag = 1;
		}
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (flag);
}

int	map_parse(t_info *info, int fd, char *first_line)
{
	t_map_list	head;
	t_map_info	map_info;
	char		*line;
	int			i;
	int			check_flag;

	head.next = NULL;
	add_map_line_tail(&head, lstnew_map_line(first_line));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_map_line_tail(&head, lstnew_map_line(line));
	}

	t_map_list *temp;
	temp = head.next;
	ft_memset(&map_info, 0, sizeof(t_map_info));
	i = 1;
	while (temp != NULL)
	{
		check_flag = check_map_one_line(temp->one_line, &map_info);
		if (check_flag == ERROR)
			return (ERROR);
		if (check_flag == 1)
		{
			map_info.height += i;
			i = 0;
		}
		i++;
		temp = temp->next;
	}
	printf("\nmin: %d\nmax: %d\nheight: %d\nwidth: %d\n", map_info.min_w, map_info.max_w, map_info.height, map_info.max_w - map_info.min_w);

	info->map = ft_calloc(sizeof(char *), map_info.height);
	temp = head.next;
	i = 0;
	while (i < map_info.height)
	{
		info->map[i] = ft_calloc(sizeof(char), map_info.max_w - map_info.min_w + 2);
		ft_strlcpy(info->map[i], temp->one_line + map_info.min_w, map_info.max_w - map_info.min_w + 2);
		printf("%s\n", info->map[i]);
		i++;
		temp = temp->next;
	}
	//오른손 법칙 알고리즘
	return (0);
}
