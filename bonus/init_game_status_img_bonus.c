/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_status_img_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:33:34 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 19:07:30 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_game_status(t_img *xpm, t_img *target)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			color = *((unsigned int *)(xpm->addr) + \
			((int)(y * (360.0 / SCREEN_H))) * 640 + \
			(int)(x * (640.0 / SCREEN_W)));
			draw_in_image(target, x, y, color);
			x++;
		}
		y++;
	}
}

int	init_game_status_img(t_info *info)
{
	t_img	xpm;

	if (init_xpm_img(info, &xpm, "asset/game_clear.xpm") == ERROR)
		return (ERROR);
	if (init_img(&info->screen.game_clear, info->mlx, \
		SCREEN_W, SCREEN_H) == ERROR)
		return (ERROR);
	draw_game_status(&xpm, &info->screen.game_clear);
	mlx_destroy_image(info->mlx, xpm.img);
	if (init_xpm_img(info, &xpm, "asset/game_over.xpm") == ERROR)
		return (ERROR);
	if (init_img(&info->screen.game_over, info->mlx, \
		SCREEN_W, SCREEN_H) == ERROR)
		return (ERROR);
	draw_game_status(&xpm, &info->screen.game_over);
	mlx_destroy_image(info->mlx, xpm.img);
	return (0);
}
