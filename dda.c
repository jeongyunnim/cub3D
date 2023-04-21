/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:03:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/21 17:06:16 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dda(t_info *info, t_mbase mbase, t_ray *ray)
{
	double	perp_dist;
	int		hit_flag;

	hit_flag = 0;
	while (hit_flag == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			mbase.map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			mbase.map.y += ray->step.y;
			ray->side = 1;
		}
		if (info->map[mbase.map.y][mbase.map.x] == '1')
		{
			hit_flag = 1;
		}
	}
	if (ray->side == 0)
	{
//		perp_dist = ray->side_dist.x - ray->delta_dist.x;
		//perp_dist = (mbase.map.x - mbase.pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
		if (ray->side_dist.x > ray->delta_dist.x)
			perp_dist = (ray->side_dist.x - ray->delta_dist.x) * ((mbase.dir.x * ray->dir.x)
				+ mbase.dir.y * ray->dir.y) / sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
		else
			perp_dist = ray->side_dist.x * ((mbase.dir.x * ray->dir.x)
				+ mbase.dir.y * ray->dir.y) / sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
	}
	else
	{
//		perp_dist = ray->side_dist.y - ray->delta_dist.y;
		//perp_dist = (mbase.map.y - mbase.pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
		if (ray->side_dist.y > ray->delta_dist.y)
			perp_dist = (ray->side_dist.y - ray->delta_dist.y) * ((mbase.dir.x * ray->dir.x)
				+ mbase.dir.y * ray->dir.y) / sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
		else
			perp_dist = ray->side_dist.y * ((mbase.dir.x * ray->dir.x)
				+ mbase.dir.y * ray->dir.y) / sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2)));
	}
	if (perp_dist <= 0.000000)
	{
		printf("****문제****\nmap(%d, %d), pos(%f, %f), camera_dir(%f, %f), side %d, ray.dir(%f, %f)\nperp: %f, side_dist(%f, %f), delta_dist(%f, %f)\n\n", mbase.map.x, mbase.map.y, mbase.pos.x, mbase.pos.y, mbase.dir.x, mbase.dir.y, ray->side, ray->dir.x, ray->dir.y, perp_dist, ray->side_dist.x, ray->side_dist.y, ray->delta_dist.x, ray->delta_dist.y);
	}
	else
		printf("map(%d, %d), pos(%f, %f), camera_dir(%f, %f), side %d, ray.dir(%f, %f)\nperp: %f, side_dist(%f, %f), delta_dist(%f, %f)\n\n", mbase.map.x, mbase.map.y, mbase.pos.x, mbase.pos.y, mbase.dir.x, mbase.dir.y, ray->side, ray->dir.x, ray->dir.y, perp_dist, ray->side_dist.x, ray->side_dist.y, ray->delta_dist.x, ray->delta_dist.y);
	return (perp_dist);
}
