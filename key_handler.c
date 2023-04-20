/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:43:52 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/20 17:05:55 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key_code, t_info *info)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;


	old_dir_x = info->mbase.dir.x;
	old_dir_y = info->mbase.dir.y;
	old_plane_x = info->mbase.plane.x;
	old_plane_y = info->mbase.plane.y;
	if (key_code == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (key_code == KEY_UP)
	{
		if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x + info->mbase.dir.x * info->mbase.move_speed)] != '1')
			info->mbase.pos.x += info->mbase.dir.x * info->mbase.move_speed;
		if (info->map[(int)(info->mbase.pos.y + info->mbase.dir.y)][(int)info->mbase.pos.x] != '1')
			info->mbase.pos.y += info->mbase.dir.y * info->mbase.move_speed;
	}
	else if (key_code == KEY_DOWN)
	{
		if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x + info->mbase.dir.x)] != '1')
			info->mbase.pos.x -= info->mbase.dir.x * info->mbase.move_speed;
		if (info->map[(int)(info->mbase.pos.y + info->mbase.dir.y)][(int)info->mbase.pos.x] != '1')
			info->mbase.pos.y -= info->mbase.dir.y * info->mbase.move_speed;
	}
	else if (key_code == KEY_RIGHT)
	{
		info->mbase.dir.x = info->mbase.dir.x * cos(-info->mbase.rot_speed) - info->mbase.dir.y * sin(-info->mbase.rot_speed);
		info->mbase.dir.y = old_dir_x * sin(-info->mbase.rot_speed) + info->mbase.dir.y * cos(-info->mbase.rot_speed);
		info->mbase.plane.x = info->mbase.plane.x * cos(-info->mbase.rot_speed) - info->mbase.plane.y * sin(-info->mbase.rot_speed);
		info->mbase.plane.y = old_plane_x * sin(-info->mbase.rot_speed) + info->mbase.plane.y * cos(-info->mbase.rot_speed);
	}
	else if (key_code == KEY_LEFT)
	{
		info->mbase.dir.x = info->mbase.dir.x * cos(info->mbase.rot_speed) - info->mbase.dir.y * sin(info->mbase.rot_speed);
		info->mbase.dir.y = old_dir_x * sin(info->mbase.rot_speed) + info->mbase.dir.y * cos(info->mbase.rot_speed);
		info->mbase.plane.x = info->mbase.plane.x * cos(info->mbase.rot_speed) - info->mbase.plane.y * sin(info->mbase.rot_speed);
		info->mbase.plane.y = old_plane_x * sin(info->mbase.rot_speed) + info->mbase.plane.y * cos(info->mbase.rot_speed);		
	}
	draw_map(info);
	return (0);
}
