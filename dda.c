/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:03:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/17 18:24:28 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dda(t_info *info, t_mbase *mbase, t_ray *ray)
{
	double	perp_dist;
	int		hit_flag;
	int		side;

	hit_flag = 0;
	while (hit_flag == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			mbase->map.x += ray->step.x;
			side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			mbase->map.y += ray->step.y;
			side = 1;
		}
		if (info->map[mbase->map.x][mbase->map.y] != 0)
		{
			hit_flag = 1;
		}
	}
	if (side == 0)
	{
		perp_dist = (mbase->map.x - mbase->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
	}
	else
	{
		perp_dist = (mbase->map.y - mbase->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
	}
	return (perp_dist);
}