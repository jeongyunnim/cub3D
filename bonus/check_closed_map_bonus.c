/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:32:18 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/26 19:29:25 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_square(t_info *info, char **map, int i, int j)
{
	if (i != 0 && j != 0 && map[i - 1][j - 1] != '1' &&
		map[i - 1][j - 1] != ' ')
		return (ERROR);
	if (j != 0 && map[i][j - 1] != '1' && map[i][j - 1] != ' ')
		return (ERROR);
	if (i != info->map_height - 1 && j != 0 && map[i + 1][j - 1]
		!= '1' && map[i + 1][j - 1] != ' ')
		return (ERROR);
	if (i != 0 && j != info->map_width - 1 && map[i - 1][j + 1] != '1'
		&& map[i - 1][j + 1] != ' ' && map[i - 1][j + 1] != '\0')
		return (ERROR);
	if (j != info->map_width - 1 && map[i][j + 1] != '1'
		&& map[i][j + 1] != ' ' && map[i][j + 1] != '\0')
		return (ERROR);
	if (i != info->map_height - 1 && j != info->map_width - 1
		&& map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != ' '
		&& map[i + 1][j + 1] != '\0')
		return (ERROR);
	if (i != 0 && map[i - 1][j] != '1' && map[i - 1][j] != ' ')
		return (ERROR);
	if (i != info->map_height - 1 && map[i + 1][j] != '1'
		&& map[i + 1][j] != ' ')
		return (ERROR);
	return (0);
}

int	check_closed_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if ((i == 0 || j == 0 || i == info->map_height - 1 \
				|| j == info->map_width - 1) && (info->map[i][j] != '1' \
				&& info->map[i][j] != ' '))
				return (ERROR);
			if (info->map[i][j] == ' ')
			{
				if (check_square(info, info->map, i, j) == ERROR)
					return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (0);
}
