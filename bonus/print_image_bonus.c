/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/05 18:59:49 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"



void	cal_locate(t_info *info, int *x, int *y)
{
	t_ipos	pos_in_block;

	pos_in_block.x = round((info->mbase.pos.x - (int)info->mbase.pos.x) * SCREEN_H / 50);
	pos_in_block.y = round((info->mbase.pos.y - (int)info->mbase.pos.y) * SCREEN_H / 50);
	*x = ((int)info->mbase.pos.x * (SCREEN_H / 50)) % (SCREEN_H / 50 * 16) + pos_in_block.x - (SCREEN_H / 50) / 4;
	*y = ((int)info->mbase.pos.y * (SCREEN_H / 50)) % ((SCREEN_H / 50 * 9)) + pos_in_block.y + (SCREEN_H / 50) / 4;
}

int	print_image(t_info *info)
{
	int	x;
	int	y;
	int			handle_index;

	mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->mini_map.img, 0, 0);
	cal_locate(info, &x, &y);
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->current.img, x, (SCREEN_H / 50) * 9 - 1 - y);
	if (info->handle_flag < - 10)
		handle_index = 0;
	else if (info->handle_flag < -5)
		handle_index = 1;
	else if (info->handle_flag < 5)
		handle_index = 2;
	else if (info->handle_flag < 10)
		handle_index = 3;
	else
		handle_index = 4;
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->handle[handle_index].img, 0, SCREEN_H / 5.5);
	return (0);
}

int	main_loop(t_info *info)
{
	input_update(info);
	draw_mini_map(info);
	print_image(info);
	return (0);
}
