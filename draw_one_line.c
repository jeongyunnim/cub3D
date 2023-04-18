/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:34 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/18 20:32:48 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_one_line(t_info *info, double perp_dist)
{
	int	wall_height;
	int	line_bottom;
	int	line_top;

	wall_height = SCREEN_H / perp_dist;//이게 뭔데
	line_bottom = (SCREEN_H / 2) - (wall_height / 2); //이걸 왜 이렇게 하는 거지?
	if (line_bottom < 0)
		line_bottom = 0;
	line_top = (SCREEN_H / 2) + (wall_height / 2);
	if (line_top >= SCREEN_H) // 여기에만 등호가 들어가는 이유는? 픽셀도 index가 0부터 시작하는 배열인가?
		line_top = SCREEN_H - 1;
	return (0);
}