/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_right_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:04:43 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/24 00:05:15 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_right(t_info *info, t_update_data data)
{
	info->mbase.dir.x = info->mbase.dir.x * cos(-info->mbase.rot_speed) \
					- info->mbase.dir.y * sin(-info->mbase.rot_speed);
	info->mbase.dir.y = data.old_dir_x * sin(-info->mbase.rot_speed) \
					+ info->mbase.dir.y * cos(-info->mbase.rot_speed);
	info->mbase.plane.x = info->mbase.plane.x * cos(-info->mbase.rot_speed) \
					- info->mbase.plane.y * sin(-info->mbase.rot_speed);
	info->mbase.plane.y = data.old_plane_x * sin(-info->mbase.rot_speed) \
					+ info->mbase.plane.y * cos(-info->mbase.rot_speed);
}

void	input_left(t_info *info, t_update_data data)
{
	info->mbase.dir.x = info->mbase.dir.x * cos(info->mbase.rot_speed) \
					- info->mbase.dir.y * sin(info->mbase.rot_speed);
	info->mbase.dir.y = data.old_dir_x * sin(info->mbase.rot_speed) \
					+ info->mbase.dir.y * cos(info->mbase.rot_speed);
	info->mbase.plane.x = info->mbase.plane.x * cos(info->mbase.rot_speed) \
					- info->mbase.plane.y * sin(info->mbase.rot_speed);
	info->mbase.plane.y = data.old_plane_x * sin(info->mbase.rot_speed) \
					+ info->mbase.plane.y * cos(info->mbase.rot_speed);
}
