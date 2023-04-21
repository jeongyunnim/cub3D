/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:34 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/21 22:12:13 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_one_line(t_info *info, t_line line, int color, int i)
{
	int j;

	j = 0;
	while (j < SCREEN_H)
	{
		if (j < line.bottom)
			draw_in_image(info, i, j, 0xeeeeee);
		else if (j < line.top)
			draw_in_image(info, i, j, color);
		else
			draw_in_image(info, i, j, 0x0);
		j++;
	}
}

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
			wall_x = (ray.side_dist.x - ray.delta_dist.x) * ray.dir.y / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2)));
		else
			wall_x = ray.side_dist.x * ray.dir.y / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2)));
	}
	else
	{
		if (ray.side_dist.y > ray.delta_dist.y)
			wall_x = (ray.side_dist.y - ray.delta_dist.y) * ray.dir.x / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2)));
		else
			wall_x = ray.side_dist.y * ray.dir.x / sqrt((pow(ray.dir.x, 2) + pow(ray.dir.y, 2)));
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
	int	tex_y;
	int		color;

	step = 1.0 * TEX_H / line.wall_height;
	tex_pos = (line.bottom - SCREEN_H / 2 + line.wall_height / 2) * step;
	i = line.bottom;
	while (i < line.top)
	{
		color = 0;
		tex_y = (int)tex_pos & (TEX_H - 1);
		tex_pos += step;
		color = info->textures[0].addr[TEX_H * tex_y + tex_x] << 24 | 
				info->textures[0].addr[TEX_H * tex_y + tex_x + 1] << 16 |
				info->textures[0].addr[TEX_H * tex_y + tex_x + 2] << 8 |
				info->textures[0].addr[TEX_H * tex_y + tex_x + 3];
		i++;
	}

	if (ray.side == 0 && ray.step.x == -1)
		texture_one_line(info, line, color, i);
	else if (ray.side == 0 && ray.step.x == 1)
		texture_one_line(info, line, color, i);
	else if (ray.side == 1 && ray.step.y == -1)
		texture_one_line(info, line, color, i);
	else
		texture_one_line(info, line, color, i);
	return (0);
}