/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fuel_img_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:24:18 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 19:07:10 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_fuel(t_info *info, t_img *xpm)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < SCREEN_H / 18)
	{
		x = 0;
		while (x < SCREEN_H / 18)
		{
			color = *((unsigned int *)(xpm->addr) + \
			((int)(y * (64.0 / (SCREEN_H / 18)))) * 64 + \
			(int)(x * (64.0 / (SCREEN_H / 18))));
			draw_in_image(&info->screen.fuel, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_fuel_bar(t_info *info)
{
	int		fuel;
	int		bar_w;
	int		bar_h;
	int		x;
	int		y;

	fuel = SCREEN_H / 18;
	bar_w = (SCREEN_W - 10 * (int)(64.0 / fuel)) - (SCREEN_W / 10 * 8 + fuel);
	bar_h = 43 * (int)(64.0 / fuel);
	y = -1;
	while (++y < bar_h)
	{
		x = -1;
		while (++x < bar_w * ((FUEL - info->fuel) / FUEL))
		{
			if (FUEL - info->fuel < FUEL / 4)
				draw_in_image(&info->screen.fuel_bar, x, y, 0xc92a2a);
			else
				draw_in_image(&info->screen.fuel_bar, x, y, 0x40c057);
		}
		while (++x < bar_w)
		{
			draw_in_image(&info->screen.fuel_bar, x, y, 0xff000000);
		}
	}
}

int	init_fuel_img(t_info *info)
{
	t_img	xpm;
	int		fuel_size;
	int		bar_w;
	int		bar_h;

	fuel_size = SCREEN_H / 18;
	if (init_xpm_img(info, &xpm, "asset/fuel.xpm") == ERROR)
		return (ERROR);
	if (init_img(&info->screen.fuel, info->mlx, fuel_size, fuel_size) == ERROR)
		return (ERROR);
	bar_w = (SCREEN_W - 10 * (int)(64.0 / fuel_size)) - \
			(SCREEN_W / 10 * 8 + fuel_size);
	bar_h = 43 * (int)(64.0 / fuel_size);
	if (init_img(&info->screen.fuel_bar, info->mlx, bar_w, bar_h) == ERROR)
		return (ERROR);
	draw_fuel(info, &xpm);
	draw_fuel_bar(info);
	mlx_destroy_image(info->mlx, xpm.img);
	return (0);
}
