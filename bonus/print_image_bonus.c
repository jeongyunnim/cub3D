/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/07 18:33:59 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cal_locate(t_info *info, int *x, int *y)
{
	t_ipos	pos_in_block;

	pos_in_block.x = round((info->mbase.pos.x - (int)info->mbase.pos.x) * info->block_size);
	pos_in_block.y = round((info->mbase.pos.y - (int)info->mbase.pos.y) * info->block_size);
	*x = ((int)info->mbase.pos.x * (info->block_size)) % (info->block_size * 16) + pos_in_block.x - (info->block_size) / 4;
	*y = ((int)info->mbase.pos.y * (info->block_size)) % ((info->block_size * 9)) + pos_in_block.y + (info->block_size) / 4;
}

int	print_image(t_info *info)
{
	int	x;
	int	y;
	int	handle_index;

	mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.full.img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.mini_map.img, 0, 0);
	cal_locate(info, &x, &y);
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.current.img, x, (SCREEN_H / 50) * 9 - 1 - y);
	if (info->flag.racing == 1) // 레이싱 모드 따로 빼기
	{
		if (info->flag.notice == 0)
		{
			mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.notice.img, 0, 0);
			return (0);
		}
		if (info->flag.handle < - 5)
			handle_index = 0;
		else if (info->flag.handle < 0)
			handle_index = 1;
		else if (info->flag.handle == 0)
			handle_index = 2;
		else if (info->flag.handle < 5)
			handle_index = 3;
		else
			handle_index = 4;
		mlx_put_image_to_window(info->mlx, info->win_mlx, info->handle[handle_index].img, 0, SCREEN_H / 5.5);
	}
	return (0);
}

int	main_loop(t_info *info)
{
	static int	fuel;
	
	if (info->flag.racing)
		fuel++;
	if (fuel >= FUEL)
		info->flag.end = 2;
	if (info->flag.end)
	{
		if (info->flag.end == 1)
			printf("goal!! dist: %f, remain fule: %d\n", \
					info->mbase.pos.x - info->racing_start, 6000 - fuel);
		else
			printf("try again fule is empty dist: %f\n", \
					info->mbase.pos.x - info->racing_start);
		exit(0);
	}
	input_update(info);
	draw_mini_map(info);
	print_image(info);
	return (0);
}
