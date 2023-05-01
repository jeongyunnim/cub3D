/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:39:15 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/01 22:22:49 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


void	door_update(t_info *info, int x, int y)
{
	double	margin;

	margin = 0.7;
	if (info->map[(int)y][(int)x] == 'D')
		info->map[(int)y][(int)x] = 'd';
	else if (info->map[(int)y][(int)x] == 'd')
		info->map[(int)y][(int)x] = 'D';
	if (info->map[(int)(y + margin)][(int)x] == 'D')
		info->map[(int)(y + margin)][(int)x] = 'd';
	else if (info->map[(int)(y + margin)][(int)x] == 'd')
		info->map[(int)(y + margin)][(int)x] = 'D';
	if (info->map[(int)y][(int)(x + margin)] == 'D')
		info->map[(int)y][(int)(x + margin)] = 'd';
	else if (info->map[(int)y][(int)(x + margin)] == 'd')
		info->map[(int)y][(int)(x + margin)] = 'D';
	if (info->map[(int)(y + margin)][(int)(x + margin)] == 'D')
		info->map[(int)(y + margin)][(int)(x + margin)] = 'd';
	else if (info->map[(int)(y + margin)][(int)(x + margin)] == 'd')
		info->map[(int)(y + margin)][(int)(x + margin)] = 'D';
	if (info->map[(int)(y - margin)][(int)x] == 'D')
		info->map[(int)(y - margin)][(int)x] = 'd';
	else if (info->map[(int)(y - margin)][(int)x] == 'd')
		info->map[(int)(y - margin)][(int)x] = 'D';
	if (info->map[(int)y][(int)(x - margin)] == 'D')
		info->map[(int)y][(int)(x - margin)] = 'd';
	else if (info->map[(int)y][(int)(x - margin)] == 'd')
		info->map[(int)y][(int)(x - margin)] = 'D';
	if (info->map[(int)(y - margin)][(int)(x - margin)] == 'D')
		info->map[(int)(y - margin)][(int)(x - margin)] = 'd';
	else if (info->map[(int)(y - margin)][(int)(x - margin)] == 'd')
		info->map[(int)(y - margin)][(int)(x - margin)] = 'D';
	if (info->map[(int)(y - margin)][(int)(x + margin)] == 'D')
		info->map[(int)(y - margin)][(int)(x + margin)] = 'd';
	else if (info->map[(int)(y - margin)][(int)(x + margin)] == 'd')
		info->map[(int)(y - margin)][(int)(x + margin)] = 'D';
	if (info->map[(int)(y + margin)][(int)(x - margin)] == 'D')
		info->map[(int)(y + margin)][(int)(x - margin)] = 'd';
	else if (info->map[(int)(y + margin)][(int)(x - margin)] == 'd')
		info->map[(int)(y + margin)][(int)(x - margin)] = 'D';
	printf("is here\n");
}
