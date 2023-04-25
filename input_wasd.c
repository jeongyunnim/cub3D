/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_wasd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:04:33 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/24 00:05:01 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_w(t_info *info)
{
	if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x \
			+ info->mbase.dir.x * info->mbase.move_speed)] != '1')
		info->mbase.pos.x += info->mbase.dir.x * info->mbase.move_speed;
	if (info->map[(int)(info->mbase.pos.y + info->mbase.dir.y \
			* info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
		info->mbase.pos.y += info->mbase.dir.y * info->mbase.move_speed;
}

void	input_s(t_info *info)
{
	if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x \
			- info->mbase.dir.x * info->mbase.move_speed)] != '1')
		info->mbase.pos.x -= info->mbase.dir.x * info->mbase.move_speed;
	if (info->map[(int)(info->mbase.pos.y - info->mbase.dir.y \
			* info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
		info->mbase.pos.y -= info->mbase.dir.y * info->mbase.move_speed;
}

void	input_a(t_info *info, t_update_data data)
{
	data.side_walk_x = info->mbase.dir.x * cos(acos(-1) / 2) \
					- info->mbase.dir.y * sin(acos(-1) / 2);
	data.side_walk_y = data.old_dir_x * sin(acos(-1) / 2) \
					+ info->mbase.dir.y * cos(acos(-1) / 2);
	if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x \
			+ data.side_walk_x * info->mbase.move_speed)] != '1')
		info->mbase.pos.x += data.side_walk_x * info->mbase.move_speed;
	if (info->map[(int)(info->mbase.pos.y + data.side_walk_y \
			* info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
		info->mbase.pos.y += data.side_walk_y * info->mbase.move_speed;
}

void	input_d(t_info *info, t_update_data data)
{
	data.side_walk_x = info->mbase.dir.x * cos(acos(-1) / 2) \
					- info->mbase.dir.y * sin(acos(-1) / 2);
	data.side_walk_y = data.old_dir_x * sin(acos(-1) / 2) \
					+ info->mbase.dir.y * cos(acos(-1) / 2);
	if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x \
			- data.side_walk_x * info->mbase.move_speed)] != '1')
		info->mbase.pos.x -= data.side_walk_x * info->mbase.move_speed;
	if (info->map[(int)(info->mbase.pos.y - data.side_walk_y \
			* info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
		info->mbase.pos.y -= data.side_walk_y * info->mbase.move_speed;
}
