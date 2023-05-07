/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:36:35 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/07 16:35:43 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	choose_color(t_info *info, t_ipos *pix)
{
	t_ipos	limit;
	int		color;

	limit.x = (info->mbase.map.x / 16) * 16 + pix->x / info->block_size;
	limit.y = (info->mbase.map.y / 9) * 9 + pix->y / info->block_size;
	if (limit.y >= info->map_height || limit.x >= info->map_width)
		color = 0x0;
	else if (info->map[limit.y][limit.x] == '1')
		color = 0x0;
	else if (info->map[limit.y][limit.x] == 'D')
		color = 0x868e96;
	else if (info->map[limit.y][limit.x] == 'B')
		color = 0xfab005;
	else
		color = 0x88141414;
	if ((pix->x % info->block_size == 0 || \
		(pix->y + 1) % info->block_size == 0) && info->racing_flag != 1)
		color = 0xffffff;
	return (color);
}

void	draw_mini_map(t_info *info)
{
	t_ipos	pix;
	int		color;

	pix.y = info->block_size * 9 - 1;
	while (pix.y >= 0)
	{	
		pix.x = 0;
		while (pix.x < info->block_size * 16)
		{
			color = choose_color(info, &pix);
			draw_in_image(&info->mini_map, pix.x, \
			info->block_size * 9 - 1 - pix.y, color);
			pix.x++;
		}
		pix.y--;
	}
	return ;
}
