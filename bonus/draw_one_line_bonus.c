/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:34 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 19:12:39 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	cal_wall_x(t_mbase *mbase, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
	{
		if (ray->side_dist.x > ray->delta_dist.x)
			wall_x = (ray->side_dist.x - ray->delta_dist.x) * ray->dir.y \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2))) + mbase->pos.y;
		else
			wall_x = ray->side_dist.x * ray->dir.y \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2))) + mbase->pos.y;
	}
	else
	{
		if (ray->side_dist.y > ray->delta_dist.y)
			wall_x = (ray->side_dist.y - ray->delta_dist.y) * ray->dir.x \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2))) + mbase->pos.x;
		else
			wall_x = ray->side_dist.y * ray->dir.x \
			/ sqrt((pow(ray->dir.x, 2) + pow(ray->dir.y, 2))) + mbase->pos.x;
	}
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	init_tex(t_mbase *mbase, t_ray *ray, t_tex *tex, t_line *line)
{
	int		tex_x;

	tex_x = (int)(cal_wall_x(mbase, ray) * (double)TEX_W);
	if (ray->side == 0 && ray->dir.x > 0)
		tex_x = TEX_W - tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex_x = TEX_W - tex_x - 1;
	tex->step = 1.0 * TEX_H / line->wall_height;
	tex->pos = (line->bottom - SCREEN_H / 2 \
			+ line->wall_height / 2) * tex->step;
	tex->x = tex_x;
}

void	get_tex_color(t_info *info, t_tex *tex, t_ray *ray)
{
	int	texture_index;

	tex->y = (int)tex->pos & (TEX_H - 1);
	tex->pos += tex->step;
	if (ray->door_hit)
		texture_index = D_SIDE;
	else if (ray->button_hit)
		texture_index = B_SIDE;
	else if (ray->goal_hit)
		texture_index = G_SIDE;
	else
	{
		if (ray->side == 0 && ray->step.x == -1)
			texture_index = W_SIDE;
		else if (ray->side == 0 && ray->step.x == 1)
			texture_index = E_SIDE;
		else if (ray->side == 1 && ray->step.y == -1)
			texture_index = S_SIDE;
		else
			texture_index = N_SIDE;
	}
	tex->color = *((unsigned int *)(info->textures[texture_index].addr) \
			+ TEX_W * tex->y + tex->x);
}

void	fill_color(t_info *info, t_line *line, t_ray *ray, t_tex *tex)
{
	int	col;

	col = 0;
	while (col < SCREEN_H)
	{
		tex->color = 0;
		if (col < line->bottom)
			tex->color = info->ceiling[0] << 16 \
			| info->ceiling[1] << 8 | info->ceiling[2];
		else if (col < line->top)
			get_tex_color(info, tex, ray);
		else
			tex->color = info->floor[0] << 16 \
			| info->floor[1] << 8 | info->floor[2];
		draw_in_image(&info->screen.full, tex->camera_x, col, tex->color);
		col++;
	}
}

int	draw_one_line(t_info *info, t_mbase *mbase, t_ray *ray, int i)
{
	t_line	line;
	t_tex	tex;

	line.wall_height = (SCREEN_H * 2) / ray->perp_dist;
	line.bottom = (SCREEN_H / 2) - (line.wall_height / 2);
	if (line.bottom < 0)
		line.bottom = 0;
	line.top = (SCREEN_H / 2) + (line.wall_height / 2);
	if (line.top >= SCREEN_H)
		line.top = SCREEN_H - 1;
	init_tex(mbase, ray, &tex, &line);
	tex.camera_x = i;
	fill_color(info, &line, ray, &tex);
	return (0);
}
