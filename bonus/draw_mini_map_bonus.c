/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:36:35 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/05 19:45:41 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_mini_map(t_info *info)
{
	int	x;
	int	y;
	int	block_size;

	block_size = SCREEN_H / 5 / 10; // block_size를 info에서 들고다니는 건?
	y = block_size * 9 - 1;
	while (y >= 0)
	{	
		x = 0;
		while (x < block_size * 16)
		{
			if ((info->mbase.map.y / 9) * 9 + y / block_size >= info->map_height || (info->mbase.map.x / 16) * 16 + x / block_size >= info->map_width)
				draw_in_image(&info->mini_map, x, block_size * 9 - 1 - y, 0x0);
			else if (info->map[(info->mbase.map.y / 9) * 9 + y / block_size][(info->mbase.map.x / 16) * 16 + x / block_size] != '1')
				draw_in_image(&info->mini_map, x, block_size * 9 - 1 - y, 0xced4daaa);
			else
				draw_in_image(&info->mini_map, x, block_size * 9 - 1 - y, 0x0);
			if (x % block_size == 0 || (y + 1) % block_size == 0)
				draw_in_image(&info->mini_map, x, block_size * 9 - 1 - y, 0xffffff);
			x++;
		}
		y--;
	}
	return ;
}
