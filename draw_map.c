/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:44:32 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/18 19:43:44 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_info *info)
{
	t_mbase	mbase;
	double	perp_wall_dist;
	int		i;

	init_map_base(info, &mbase);
	i = 0;
	while (i <= SCREEN_W)
	{
		perp_wall_dist = cal_perp_dist(info, &mbase, 2 * i / (double)SCREEN_W - 1);
		//draw_use_mlx
		i++;
	}
	return (0);
}