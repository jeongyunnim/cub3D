/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:39:15 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/05 16:01:13 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	target_set(t_ipos target[8], double x, double y, double margin)
{
	target[0].x = (int)x;
	target[0].y = (int)(y + margin);
	target[1].x = (int)(x + margin);
	target[1].y = (int)y;
	target[2].x = (int)(x + margin);
	target[2].y = (int)(y + margin);
	target[3].x = (int)x;
	target[3].y = (int)(y - margin);
	target[4].x = (int)(x - margin);
	target[4].y = (int)y;
	target[5].x = (int)(x - margin);
	target[5].y = (int)(y - margin);
	target[6].x = (int)(x + margin);
	target[6].y = (int)(y - margin);
	target[7].x = (int)(x - margin);
	target[7].y = (int)(y + margin);
}

static int	is_dup_target(t_ipos target[8], int idx)
{
	int	i;

	i = idx - 1;
	while (i >= 0)
	{
		if (target[i].x == target[idx].x && target[i].y == target[idx].y)
			return (1);
		i--;
	}
	return (0);
}

int	is_same_as_pos(t_ipos target[8], int idx, double x, double y)
{
	if (target[idx].x == (int)x && target[idx].y == (int)y)
		return (1);
	return (0);
}

void	door_update(t_info *info, double x, double y)
{
	t_ipos	target[8];
	double	margin;
	int		i;

	margin = 0.7;
	i = 0;
	target_set(target, x, y, margin);
	while (i < 8)
	{
		if (!is_dup_target(target, i))
		{
			if (!is_same_as_pos(target, i, x, y))
			{
				if (info->map[target[i].y][target[i].x] == 'D')
					info->map[target[i].y][target[i].x] = 'd';
				else if (info->map[target[i].y][target[i].x] == 'd')
					info->map[target[i].y][target[i].x] = 'D';
			}
		}
		i++;
	}
}
