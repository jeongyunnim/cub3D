/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handle_img_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:09:03 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 22:02:23 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_handle(t_info *info, t_img *xpm, int size, int i)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			color = *((unsigned int *)(xpm->addr) + \
			((int)(y * (300.0 / size))) * 300 + (int)(x * (300.0 / size)));
			draw_in_image(&info->handle[i], x, y, color);
			x++;
		}
		y++;
	}
}

int	init_handle_img(t_info *info)
{
	int		i;
	int		size;
	t_img	xpm[5];

	if (init_xpm_img(info, &xpm[0], "asset/handle_1.xpm") == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &xpm[1], "asset/handle_2.xpm") == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &xpm[2], "asset/handle_3.xpm") == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &xpm[3], "asset/handle_4.xpm") == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &xpm[4], "asset/handle_5.xpm") == ERROR)
		return (ERROR);
	i = 0;
	size = SCREEN_W / 6 * 5;
	while (i < 5)
	{
		if (init_new_img(info, &info->handle[i], size, size) == ERROR)
			return (ERROR);
		draw_handle(info, &xpm[i], size, i);
		mlx_destroy_image(info->mlx, xpm[i].img);
		i++;
	}
	return (0);
}
