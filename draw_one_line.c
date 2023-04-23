/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:34 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/23 23:40:37 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_one_line(t_info *info, t_mbase *mbase, t_ray ray, int i)
{
	t_line	line;

	line.wall_height = SCREEN_H / ray.perp_dist;
	line.bottom = (SCREEN_H / 2) - (line.wall_height / 2);
	if (line.bottom < 0)
		line.bottom = 0;
	line.top = (SCREEN_H / 2) + (line.wall_height / 2);
	if (line.top >= SCREEN_H)
		line.top = SCREEN_H - 1;
	
	double	wall_x;

	if (ray.side == 0)
	{
		if (ray.side_dist.x > ray.delta_dist.x)
			wall_x = (ray.side_dist.x - ray.delta_dist.x) * ray.dir.y / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2))) + mbase->pos.y;
		else
			wall_x = ray.side_dist.x * ray.dir.y / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2))) + mbase->pos.y;
	}
	else
	{
		if (ray.side_dist.y > ray.delta_dist.y)
			wall_x = (ray.side_dist.y - ray.delta_dist.y) * ray.dir.x / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2))) + mbase->pos.x;
		else
			wall_x = ray.side_dist.y * ray.dir.x / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2))) + mbase->pos.x;
	}
	wall_x -= floor(wall_x);

	int	tex_x;

	tex_x = (int)(wall_x * (double)TEX_W);
	if(ray.side == 0 && ray.dir.x > 0) 
		tex_x = TEX_W - tex_x - 1;
	if(ray.side == 1 && ray.dir.y < 0)
		tex_x = TEX_W - tex_x - 1;

	double	step;
	double	tex_pos;
	int		tex_y;
	unsigned int		color;
	int		col;

	step = 1.0 * TEX_H / line.wall_height;
	tex_pos = (line.bottom - SCREEN_H / 2 + line.wall_height / 2) * step;
	col = 0;
	while (col < SCREEN_H)
	{
		if (col < line.bottom)
			draw_in_image(info, i, col, info->ceiling[0] << 16| info->ceiling[1] << 8| info->ceiling[2]);
		else if (col < line.top)
		{
			color = 0;
			tex_y = (int)tex_pos & (TEX_H - 1);
			tex_pos += step;
			if (ray.side == 0 && ray.step.x == -1)
				color = *((unsigned int*)(info->textures[W_SIDE].addr) + TEX_W * tex_y + tex_x);
			else if (ray.side == 0 && ray.step.x == 1)
				color = *((unsigned int*)(info->textures[E_SIDE].addr) + TEX_W * tex_y + tex_x);
			else if (ray.side == 1 && ray.step.y == -1)
				color = *((unsigned int*)(info->textures[S_SIDE].addr) + TEX_W * tex_y + tex_x);
			else
				color = *((unsigned int*)(info->textures[N_SIDE].addr) + TEX_W * tex_y + tex_x);
			draw_in_image(info, i, col, color);
		}
		else
			draw_in_image(info, i, col, info->floor[0] << 16| info->floor[1] << 8| info->floor[2]);
		col++;
	}
	return (0);
}