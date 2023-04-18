/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:03:16 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/18 16:25:51 by jeseo            ###   ########.fr       */
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
		else
		{
			if (line[i] == 'N' || line[i] == 'W' ||line[i] == 'E' ||line[i] == 'S' || line[i] == '1' || line[i] == '0')
			{
				flag = 1;
				if (i < map->min_w)
					map->min_w = i;
				if (i > map->max_w)
					map->max_w = i;
			}
		}
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (flag);
}

int	check_all_line(t_map_info *map_info, t_map_list *temp)
{
	int	i;
	int	check_flag;


	ft_memset(map_info, 0, sizeof(t_map_info));
	i = 1;
	while (temp != NULL)
	{
		check_flag = check_map_one_line(temp->one_line, map_info);
		if (check_flag == ERROR)
			return (ERROR);
		if (check_flag == 1)
		{
			map_info->height += i;
			i = 0;
		}
		i++;
		temp = temp->next;
	}
	printf("\nmin: %d\nmax: %d\nheight: %d\nwidth: %d\n", map_info->min_w, map_info->max_w, map_info->height, map_info->max_w - map_info->min_w + 1);
	return (0);
}

void	define_map_size(t_info *info, t_map_info *map_info, t_map_list *temp)
{
	int	i;
	int	j;

	info->map_height = map_info->height;
	info->map_width = map_info->max_w - map_info->min_w + 1;
	info->map = ft_calloc(sizeof(char *), info->map_height);
	i = 0;
	while (i < map_info->height)
	{
		j = info->map_width;
		info->map[i] = ft_calloc(sizeof(char), info->map_width + 1);
		ft_strlcpy(info->map[i], temp->one_line + map_info->min_w, info->map_width + 1);
		while (--j)
		{
			if (info->map[i][j] == 0)
				info->map[i][j] = ' ';
			else
				break ;
		}
		printf("%s||%d\n", info->map[i], i);
		i++;
		temp = temp->next;
	}
}

void	free_map_list(t_map_list *target)
{
	t_map_list *move_ptr;
	t_map_list *temp;

	if (target == NULL)
		return ;
	move_ptr = target;
	while (move_ptr != NULL)
	{
		temp = move_ptr->next;
		free(move_ptr->one_line);
		free(move_ptr);
		move_ptr = temp;
	}
}

int	map_parse(t_info *info, int fd, char *first_line)
{
	t_map_list	head;
	t_map_info	map_info;
	char		*line;

	head.next = NULL;
	add_map_line_tail(&head, lstnew_map_line(first_line));
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
		ft_putstr_fd("Error\nInvalid map component\n", 2);
		free_map_list(head.next);
		return (ERROR);
	}
	define_map_size(info, &map_info, head.next);
	free_map_list(head.next);
	if (check_closed_map(info) == ERROR)
	{
		ft_putstr_fd("Error\nMap is not closed\n", 2);
		return (ERROR);
	}
	return (0);
}
