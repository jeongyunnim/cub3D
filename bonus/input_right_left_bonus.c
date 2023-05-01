/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_right_left_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:04:43 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/01 22:02:38 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	input_right(t_info *info, t_update_data data)
{
	info->handle_flag = 4;
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
	info->handle_flag = 0;
	info->mbase.dir.x = info->mbase.dir.x * cos(info->mbase.rot_speed) \
					- info->mbase.dir.y * sin(info->mbase.rot_speed);
	info->mbase.dir.y = data.old_dir_x * sin(info->mbase.rot_speed) \
					+ info->mbase.dir.y * cos(info->mbase.rot_speed);
	info->mbase.plane.x = info->mbase.plane.x * cos(info->mbase.rot_speed) \
					- info->mbase.plane.y * sin(info->mbase.rot_speed);
	info->mbase.plane.y = data.old_plane_x * sin(info->mbase.rot_speed) \
					+ info->mbase.plane.y * cos(info->mbase.rot_speed);
}
