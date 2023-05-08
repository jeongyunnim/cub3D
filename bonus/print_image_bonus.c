/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 20:14:56 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cal_locate(t_info *info, int *x, int *y)
{
	t_ipos	pos_in_block;

	pos_in_block.x = round((info->mbase.pos.x - \
		(int)info->mbase.pos.x) * info->block_size);
	pos_in_block.y = round((info->mbase.pos.y - \
		(int)info->mbase.pos.y) * info->block_size);
	*x = ((int)info->mbase.pos.x * (info->block_size)) % \
		(info->block_size * 16) + pos_in_block.x - (info->block_size) / 4;
	*y = ((int)info->mbase.pos.y * (info->block_size)) % \
		((info->block_size * 9)) + pos_in_block.y + (info->block_size) / 4;
}

int	define_handle_index(t_info	*info)
{
	int	handle_index;

	if (info->flag.handle < -3)
		handle_index = 0;
	else if (info->flag.handle < 0)
		handle_index = 1;
	else if (info->flag.handle == 0)
		handle_index = 2;
	else if (info->flag.handle < 3)
		handle_index = 3;
	else
		handle_index = 4;
	return (handle_index);
}

void	racing_mode_print(t_info *info)
{
	int	handle_index;

	handle_index = define_handle_index(info);
	mlx_put_image_to_window(info->mlx, info->win_mlx, \
		info->handle[handle_index].img, 0, SCREEN_H / 5.5);
	mlx_put_image_to_window(info->mlx, info->win_mlx, \
		info->screen.fuel.img, SCREEN_W / 10 * 8, 0);
	mlx_put_image_to_window(info->mlx, info->win_mlx, \
		info->screen.fuel_bar.img, (SCREEN_W / 10 * 8) + \
		(int)((SCREEN_H / 18)), 10 * (int)(64.0 / (SCREEN_H / 18)));
	if (info->flag.end)
	{
		if (info->flag.end == SUCCESS)
			mlx_put_image_to_window(info->mlx, info->win_mlx, \
				info->screen.game_clear.img, 0, 0);
		else
			mlx_put_image_to_window(info->mlx, info->win_mlx, \
				info->screen.game_over.img, 0, 0);
	}
}

int	print_image(t_info *info)
{
	int	x;
	int	y;

	mlx_put_image_to_window(info->mlx, info->win_mlx, \
			info->screen.full.img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win_mlx, \
			info->screen.mini_map.img, 0, 0);
	cal_locate(info, &x, &y);
	mlx_put_image_to_window(info->mlx, info->win_mlx, \
			info->screen.current.img, x, (SCREEN_H / 50) * 9 - 1 - y);
	if (info->flag.wait == 1 && info->flag.notice == 0)
	{
		mlx_put_image_to_window(info->mlx, info->win_mlx, \
			info->screen.notice.img, 0, 0);
		return (0);
	}
	if (info->flag.racing == 1)
		racing_mode_print(info);
	return (0);
}

int	main_loop(t_info *info)
{
	static int	fuel;

	if (info->flag.racing)
	{
		fuel++;
		info->fuel = fuel;
	}
	if (fuel >= FUEL)
		info->flag.end = FAILURE;
	if (info->flag.end)
	{
		if (!info->flag.wait && info->flag.end == SUCCESS)
			printf("goal!! dist: %f, remain fule: %d\n", \
					info->mbase.pos.x - info->racing_start, 6000 - fuel);
		else if (!info->flag.wait)
			printf("try again fule is empty dist: %f\n", \
					info->mbase.pos.x - info->racing_start);
		info->flag.wait = 1;
	}
	input_update(info);
	draw_mini_map(info);
	draw_fuel_bar(info);
	print_image(info);
	return (0);
}
