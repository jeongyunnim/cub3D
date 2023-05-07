/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_right_left_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:04:43 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/07 18:29:11 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	limit_dir_in_racing_right(t_info *info, t_update_data *data)
{
	t_dpos	temp;
	double	limit;

	limit = acos(-1) * (4.0 / 9);
	temp.x = info->mbase.dir.x * cos(-info->mbase.rot_speed) \
				- info->mbase.dir.y * sin(-info->mbase.rot_speed);
	temp.y = data->old_dir_x * sin(-info->mbase.rot_speed) \
				+ info->mbase.dir.y * cos(-info->mbase.rot_speed);
	if (atan(temp.y / temp.x) < limit && atan(temp.y / temp.x) > -limit)
		return (1);
	return (0);
}

int	limit_dir_in_racing_left(t_info *info, t_update_data *data)
{
	t_dpos	temp;
	double	limit;

	limit = acos(-1) * (4.0 / 9);
	temp.x = info->mbase.dir.x * cos(info->mbase.rot_speed) \
				- info->mbase.dir.y * sin(info->mbase.rot_speed);
	temp.y = data->old_dir_x * sin(info->mbase.rot_speed) \
				+ info->mbase.dir.y * cos(info->mbase.rot_speed);
	if (atan(temp.y / temp.x) < limit && atan(temp.y / temp.x) > -limit)
		return (1);
	return (0);
}

void	input_right(t_info *info, t_update_data data)
{
	info->flag.handle += 1;
	if (!info->flag.racing || limit_dir_in_racing_right(info, &data))
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
}

void	input_left(t_info *info, t_update_data data)
{
	info->flag.handle -= 1;
	if (!info->flag.racing || limit_dir_in_racing_left(info, &data))
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
}
