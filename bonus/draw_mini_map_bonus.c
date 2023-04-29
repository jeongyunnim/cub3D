/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:36:35 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/28 21:37:18 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    draw_mini_map(t_info *info)
{
	int x;
	int y;
	int block_size;

	block_size = SCREEN_H / 5 / 10;
	y = 0;
	// printf("꼭짓점 (%d,%d) \n", ((int)info->mbase.pos.y / 9) * 9, ((int)info->mbase.pos.x / 16) / 16);
	while (y < block_size * 9 - 1)
	{	
		x = 0;
		while (x < block_size * 16)
		{
			if (((int)info->mbase.pos.y / 9) * 9 + y / block_size >= info->map_height || ((int)info->mbase.pos.x / 16) * 16 >= info->map_width)
				draw_in_image(&info->mini_map, x, y, 0x0);
			else if (info->map[((int)info->mbase.pos.y / 9) * 9 + y / block_size][((int)info->mbase.pos.x / 16) * 16 + x / block_size] != '1')
				draw_in_image(&info->mini_map, x, y, 0xced4daaa);
			else
				draw_in_image(&info->mini_map, x, y, 0x0);
			if (x % block_size == 0)
				draw_in_image(&info->mini_map, x, y, 0xffffff);
			if (y % block_size == 0)
				draw_in_image(&info->mini_map, x, y, 0xffffff);
			x++;
		}
		y++;
	}
	return ;
}

//맵  area 별로 나누어서 표시 함.
		// while (x < block_size * 16)
		// {
		// 	if (((int)info->mbase.pos.y / 9) * 9 + y / block_size >= info->map_height || ((int)info->mbase.pos.x / 16) * 16 >= info->map_width)
		// 		draw_in_image(&info->mini_map, x, y, 0x0);
		// 	else if (info->map[((int)info->mbase.pos.y / 9) * 9 + y / block_size][((int)info->mbase.pos.x / 16) * 16 + x / block_size] != '1')
		// 		draw_in_image(&info->mini_map, x, y, 0xced4daaa);
		// 	else
		// 		draw_in_image(&info->mini_map, x, y, 0x0);
		// 	if (x % block_size == 0)
		// 		draw_in_image(&info->mini_map, x, y, 0xffffff);
		// 	if (y % block_size == 0)
		// 		draw_in_image(&info->mini_map, x, y, 0xffffff);
		// 	x++;
		// }