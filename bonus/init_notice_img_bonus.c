/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_notice_img_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:06:03 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/07 19:45:09 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_notice(t_info *info, t_img *xpm)
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
			draw_in_image(&info->screen.notice, x, y, color);
			x++;
		}
		y++;
	}
}

int	init_notice_img(t_info *info)
{
	t_img	xpm;

	if (init_xpm_img(info, &xpm, "asset/notice.xpm") == ERROR)
		return (ERROR);
	if (init_img(&info->screen.notice, info->mlx, SCREEN_W, SCREEN_H) == ERROR)
		return (ERROR);
	draw_notice(info, &xpm);
	mlx_destroy_image(info->mlx, xpm.img);
	return (0);
}
