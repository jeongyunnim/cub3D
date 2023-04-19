/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_perp_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:22 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/19 20:30:40 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ray->side_dist.x = (mbase->pos.x + 1.0 - mbase->map.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (mbase->pos.y - mbase->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (mbase->pos.y + 1.0 - mbase->map.y) * ray->delta_dist.y;
	}
}

void	cal_perp_dist(t_info *info, t_mbase *mbase, t_ray *ray, double camera)
{
	ray->delta_dist.x = 1e30;
	ray->delta_dist.y = 1e30;
	ray->dir.x = mbase->dir.x + (mbase->plane.x * camera);
	ray->dir.y = mbase->dir.y + (mbase->plane.y * camera);
	//if (ray->dir.x != 0)
	//	ray->delta_dist.x = fabs(1 / ray->dir.x);
	//if (ray->dir.y != 0)
	//	ray->delta_dist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x != 0)
		ray->delta_dist.x = sqrt(1 + pow(ray->dir.y, 2) / pow(ray->dir.x, 2));
	if (ray->dir.y != 0)
		ray->delta_dist.y = sqrt(1 + pow(ray->dir.x, 2) / pow(ray->dir.y, 2));
	init_side_dist(mbase, ray);
	ray->perp_dist = dda(info, *mbase, ray);
}
