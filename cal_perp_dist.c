/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_perp_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:22 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/15 21:50:14 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	cal_perp_dist(t_mbase *mbase, double camera)
{
	t_dpos	ray;

	ray.x = mbase->dir.x + (mbase->plane.x * camera);
	ray.y = mbase->dir.y + (mbase->plane.y * camera);
}
