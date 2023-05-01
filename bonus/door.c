/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:10:38 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/01 22:18:05 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_around_D(t_info *info, double x, double y)
{
	double	margin;

	margin = 0.05;
	if (info->map[(int)y][(int)x] == 'D')
		return (1);
	else if (info->map[(int)(y + margin)][(int)x] == 'D')
		return (1);
	else if (info->map[(int)y][(int)(x + margin)] == 'D')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x + margin)] == 'D')
		return (1);
	else if (info->map[(int)(y - margin)][(int)x] == 'D')
		return (1);
	else if (info->map[(int)y][(int)(x - margin)] == 'D')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x - margin)] == 'D')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x + margin)] == 'D')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x - margin)] == 'D')
		return (1);
	return (0);
}

int	is_around_d(t_info *info, double x, double y)
{
	double	margin;

	margin = 0.05;
	if (info->map[(int)y][(int)x] == 'd')
		return (1);
	else if (info->map[(int)(y + margin)][(int)x] == 'd')
		return (1);
	else if (info->map[(int)y][(int)(x + margin)] == 'd')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x + margin)] == 'd')
		return (1);
	else if (info->map[(int)(y - margin)][(int)x] == 'd')
		return (1);
	else if (info->map[(int)y][(int)(x - margin)] == 'd')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x - margin)] == 'd')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x + margin)] == 'd')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x - margin)] == 'd')
		return (1);
	return (0);
}

int	is_around_D2(t_info *info, double x, double y)
{
	double	margin;

	margin = 0.7;
	if (info->map[(int)(y + margin)][(int)x] == 'D')
		return (1);
	else if (info->map[(int)y][(int)(x + margin)] == 'D')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x + margin)] == 'D')
		return (1);
	else if (info->map[(int)(y - margin)][(int)x] == 'D')
		return (1);
	else if (info->map[(int)y][(int)(x - margin)] == 'D')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x - margin)] == 'D')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x + margin)] == 'D')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x - margin)] == 'D')
		return (1);
	return (0);
}

int	is_around_d2(t_info *info, double x, double y)
{
	double	margin;

	margin = 0.7;
	if (info->map[(int)(y + margin)][(int)x] == 'd')
		return (1);
	else if (info->map[(int)y][(int)(x + margin)] == 'd')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x + margin)] == 'd')
		return (1);
	else if (info->map[(int)(y - margin)][(int)x] == 'd')
		return (1);
	else if (info->map[(int)y][(int)(x - margin)] == 'd')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x - margin)] == 'd')
		return (1);
	else if (info->map[(int)(y - margin)][(int)(x + margin)] == 'd')
		return (1);
	else if (info->map[(int)(y + margin)][(int)(x - margin)] == 'd')
		return (1);
	return (0);
}

int	is_in_door(t_info *info)
{
	if (info->map[info->mbase.map.y][info->mbase.map.x] == 'D' \
			|| info->map[info->mbase.map.y][info->mbase.map.x] == 'd')
		return (1);
	else
		return (0);
}

int	is_around_door(t_info *info)
{
	if (is_in_door(info))
		return (0);
	if (is_around_D2(info, info->mbase.pos.x, info->mbase.pos.y) \
			|| is_around_d2(info, info->mbase.pos.x, info->mbase.pos.y))
		return (1);
	else
		return (0);
}

