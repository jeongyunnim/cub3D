/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:03:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/06 14:53:39 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static double	hit_up_down(t_mbase mbase, t_ray *ray)
{
	double	perp_dist;

	if (ray->side_dist.y > ray->delta_dist.y)
		perp_dist = (ray->side_dist.y - ray->delta_dist.y) \
			* (mbase.dir.x * ray->dir.x + mbase.dir.y * ray->dir.y) \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
	else
		perp_dist = ray->side_dist.y * (mbase.dir.x * ray->dir.x \
			+ mbase.dir.y * ray->dir.y) \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
	return (perp_dist);
}

static double	hit_right_left(t_mbase mbase, t_ray *ray)
{
	double	perp_dist;

	if (ray->side_dist.x > ray->delta_dist.x)
		perp_dist = (ray->side_dist.x - ray->delta_dist.x) \
			* (mbase.dir.x * ray->dir.x + mbase.dir.y * ray->dir.y) \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
	else
		perp_dist = ray->side_dist.x * (mbase.dir.x * ray->dir.x \
			+ mbase.dir.y * ray->dir.y) \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
	return (perp_dist);
}

static double	dda_result(t_mbase mbase, t_ray *ray)
{
	double	perp_dist;

	if (ray->side == 0)
	{
		perp_dist = hit_right_left(mbase, ray);
	}
	else
	{
		perp_dist = hit_up_down(mbase, ray);
	}
	return (perp_dist);
}

void	ray_shooting(t_mbase *mbase, t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		mbase->map.x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		mbase->map.y += ray->step.y;
		ray->side = 1;
	}
}

double	dda(t_info *info, t_mbase mbase, t_ray *ray)
{
	int		hit_flag;

	hit_flag = 0;
	ray->door_hit = 0;
	ray->button_hit = 0;
	while (hit_flag == 0)
	{
		ray_shooting(&mbase, ray);
		if (info->map[mbase.map.y][mbase.map.x] == '1' \
				|| info->map[mbase.map.y][mbase.map.x] == 'D' \
				|| info->map[mbase.map.y][mbase.map.x] == 'B')
		{
			hit_flag = 1;
			if (info->map[mbase.map.y][mbase.map.x] == 'D')
				ray->door_hit = 1;
			if (info->map[mbase.map.y][mbase.map.x] == 'B')
				ray->button_hit = 1;
		}
	}
	return (dda_result(mbase, ray));
}
