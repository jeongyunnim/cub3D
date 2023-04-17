/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:44:32 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/17 21:42:14 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_info *info)
{
	t_mbase	mbase;

	t_dpos	ray;
	t_dpos	side_dist;
	t_dpos	delta_dist;
	t_ipos	step;

	int		hit;
	int		side;

	double	perp_wall_dist;
	int		i;

	init_map_base(info, &mbase);
	i = 0;
	while (i <= info->map_width)
	{
		perp_wall_dist = cal_perp_dist(info, &mbase, 2 * i / (double)info->map_width - 1);
		//draw_use_mlx
		i++;
	}
	return (0);
}