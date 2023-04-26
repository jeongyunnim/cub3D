/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_perp_dist_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:22 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/26 19:29:43 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_side_dist(t_mbase *mbase, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (mbase->pos.x - mbase->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (mbase->map.x + 1.0 - mbase->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (mbase->pos.y - mbase->map.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (mbase->map.y + 1.0 - mbase->pos.y)
			* ray->delta_dist.y;
	}
}

void	cal_perp_dist(t_info *info, t_mbase *mbase, t_ray *ray, double camera)
{
	ray->delta_dist.x = 1e30;
	ray->delta_dist.y = 1e30;
	ray->dir.x = mbase->dir.x + (mbase->plane.x * camera);
	ray->dir.y = mbase->dir.y + (mbase->plane.y * camera);
	if (ray->dir.x != 0)
		ray->delta_dist.x = sqrt(1 + pow(ray->dir.y, 2) / pow(ray->dir.x, 2));
	if (ray->dir.y != 0)
		ray->delta_dist.y = sqrt(1 + pow(ray->dir.x, 2) / pow(ray->dir.y, 2));
	init_side_dist(mbase, ray);
	ray->perp_dist = dda(info, *mbase, ray);
}
