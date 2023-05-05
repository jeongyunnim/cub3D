/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 02:00:55 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/01 19:22:36 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_valid_value_idx(t_map_info *map, char *line, int i, int *flag)
{
	if (line[i] != '0' && line[i] != '1' && line[i] != 'D' && line[i] != ' ' \
			&& line[i] != '\n' && line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'E' && line[i] != 'W' && line[i] != 'G' \
			&& line[i] != 'd')
		return (ERROR);
	else
	{
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E' \
			|| line[i] == 'S' || line[i] == '1' || line[i] == '0')
		{
			*flag = 1;
			if (i < map->min_w)
				map->min_w = i;
			if (i > map->max_w)
				map->max_w = i;
		}
	}
	if (line[i] == '\n')
		line[i] = '\0';
	return (1);
}

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
		if (check_valid_value_idx(map, line, i, &flag) == ERROR)
			return (ERROR);
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
	return (0);
}

void	define_map_size(t_info *info, t_map_info *map_info, t_map_list *temp)
{
	int	i;
	int	j;

	info->map_height = map_info->height;
	info->map_width = map_info->max_w - map_info->min_w + 1;
	info->map = ft_calloc(sizeof(char *), info->map_height);
	i = map_info->height - 1;
	while (i >= 0)
	{
		j = info->map_width;
		info->map[i] = ft_calloc(sizeof(char), info->map_width + 1);
		ft_strlcpy(info->map[i], temp->one_line + map_info->min_w, \
				info->map_width + 1);
		while (--j)
		{
			if (info->map[i][j] == 0)
				info->map[i][j] = ' ';
			else
				break ;
		}
		printf("%s||%d\n", info->map[i], i);
		i--;
		temp = temp->next;
	}
}

void	free_map_list(t_map_list *target)
{
	t_map_list	*move_ptr;
	t_map_list	*temp;

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
