/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:34 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/19 19:59:55 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_one_line(t_info *info, t_line line, t_side color, int i)
{
	int j;

	j = 0;
	while (j < SCREEN_H)
	{
		if (j < line.bottom)
			mlx_pixel_put(info->mlx, info->win_mlx, i, j, F_SIDE);
		else if (j < line.top)
			mlx_pixel_put(info->mlx, info->win_mlx, i, j, color);
		else
			mlx_pixel_put(info->mlx, info->win_mlx, i, j, C_SIDE);
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
	if (ray.side == 0 && ray.step.x == -1)
		color_one_line(info, line, E_SIDE, i);
	else if (ray.side == 0 && ray.step.x == 1)
		color_one_line(info, line, W_SIDE, i);
	else if (ray.side == 1 && ray.step.y == -1)
		color_one_line(info, line, N_SIDE, i);
	else
		color_one_line(info, line, S_SIDE, i);
	return (0);
}