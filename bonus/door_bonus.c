/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:10:38 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/05 16:00:27 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_around_locked_d(t_info *info, double x, double y, double margin)
{
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

int	is_around_open_d(t_info *info, double x, double y, double margin)
{
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

int	is_around_door(t_info *info)
{
	if (is_around_locked_d(info, info->mbase.pos.x, info->mbase.pos.y, 0.7) \
			|| is_around_open_d(info, info->mbase.pos.x, info->mbase.pos.y, \
				0.7))
		return (1);
	else
		return (0);
}
