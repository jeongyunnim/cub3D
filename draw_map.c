/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:44:32 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/19 20:55:04 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_info *info)
{
	t_ray	ray;
	int		i;

	i = 0;
	while (i < SCREEN_W)
	{
		cal_perp_dist(info, &info->mbase, &ray, 2 * i / (double)SCREEN_W - 1);
		draw_one_line(info, &info->mbase, ray, i);
		i++;
	}
	return (0);
}