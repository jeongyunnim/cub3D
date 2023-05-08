/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_current_img_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:03:27 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 22:01:05 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_current_img(t_info *info)
{
	int	x;
	int	y;
	int	circle;

	circle = info->block_size / 4;
	if (init_new_img(info, &info->screen.current, info->block_size / 2, \
				info->block_size / 2) == ERROR)
		return (ERROR);
	y = 0;
	while (y < info->block_size / 2)
	{
		x = 0;
		while (x < info->block_size / 2)
		{
			if (circle >= sqrtf(powf(circle - x, 2) + powf(circle - y, 2)))
				draw_in_image(&info->screen.current, x, y, 0xfa5252);
			else
				draw_in_image(&info->screen.current, x, y, 0xff000000);
			x++;
		}
		y++;
	}
	return (0);
}
