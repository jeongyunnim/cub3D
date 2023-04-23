/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:43:52 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/23 22:16:48 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input_update(t_info *info)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;
	double	side_walk_x;
	double	side_walk_y;


	old_dir_x = info->mbase.dir.x;
	old_dir_y = info->mbase.dir.y;
	old_plane_x = info->mbase.plane.x;
	old_plane_y = info->mbase.plane.y;
	if (info->input[INPUT_W] == 1)
	{
		if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x + info->mbase.dir.x * info->mbase.move_speed)] != '1')
			info->mbase.pos.x += info->mbase.dir.x * info->mbase.move_speed;
		if (info->map[(int)(info->mbase.pos.y + info->mbase.dir.y * info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
			info->mbase.pos.y += info->mbase.dir.y * info->mbase.move_speed;
	}
	if (info->input[INPUT_S] == 1)
	{
		if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x - info->mbase.dir.x * info->mbase.move_speed)] != '1')
			info->mbase.pos.x -= info->mbase.dir.x * info->mbase.move_speed;
		if (info->map[(int)(info->mbase.pos.y - info->mbase.dir.y * info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
			info->mbase.pos.y -= info->mbase.dir.y * info->mbase.move_speed;
	}
	if (info->input[INPUT_A] == 1)
	{
		side_walk_x = info->mbase.dir.x * cos(acos(-1) / 2) - info->mbase.dir.y * sin(acos(-1) / 2);
		side_walk_y = old_dir_x * sin(acos(-1) / 2) + info->mbase.dir.y * cos(acos(-1) / 2);
		if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x + side_walk_x * info->mbase.move_speed)] != '1')
			info->mbase.pos.x += side_walk_x * info->mbase.move_speed;
		if (info->map[(int)(info->mbase.pos.y + side_walk_y * info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
			info->mbase.pos.y += side_walk_y * info->mbase.move_speed;
	}
	if (info->input[INPUT_D] == 1)
	{
		side_walk_x = info->mbase.dir.x * cos(acos(-1) / 2) - info->mbase.dir.y * sin(acos(-1) / 2);
		side_walk_y = old_dir_x * sin(acos(-1) / 2) + info->mbase.dir.y * cos(acos(-1) / 2);
		if (info->map[(int)info->mbase.pos.y][(int)(info->mbase.pos.x - side_walk_x * info->mbase.move_speed)] != '1')
			info->mbase.pos.x -= side_walk_x * info->mbase.move_speed;
		if (info->map[(int)(info->mbase.pos.y - side_walk_y * info->mbase.move_speed)][(int)info->mbase.pos.x] != '1')
			info->mbase.pos.y -= side_walk_y * info->mbase.move_speed;
	}
	if (info->input[INPUT_RIGHT] == 1)
	{
		info->mbase.dir.x = info->mbase.dir.x * cos(-info->mbase.rot_speed) - info->mbase.dir.y * sin(-info->mbase.rot_speed);
		info->mbase.dir.y = old_dir_x * sin(-info->mbase.rot_speed) + info->mbase.dir.y * cos(-info->mbase.rot_speed);
		info->mbase.plane.x = info->mbase.plane.x * cos(-info->mbase.rot_speed) - info->mbase.plane.y * sin(-info->mbase.rot_speed);
		info->mbase.plane.y = old_plane_x * sin(-info->mbase.rot_speed) + info->mbase.plane.y * cos(-info->mbase.rot_speed);
	}
	if (info->input[INPUT_LEFT] == 1)
	{
		info->mbase.dir.x = info->mbase.dir.x * cos(info->mbase.rot_speed) - info->mbase.dir.y * sin(info->mbase.rot_speed);
		info->mbase.dir.y = old_dir_x * sin(info->mbase.rot_speed) + info->mbase.dir.y * cos(info->mbase.rot_speed);
		info->mbase.plane.x = info->mbase.plane.x * cos(info->mbase.rot_speed) - info->mbase.plane.y * sin(info->mbase.rot_speed);
		info->mbase.plane.y = old_plane_x * sin(info->mbase.rot_speed) + info->mbase.plane.y * cos(info->mbase.rot_speed);		
	}
	info->mbase.map.x = (int)info->mbase.pos.x;
	info->mbase.map.y = (int)info->mbase.pos.y;
	draw_map(info);
	print_image(info);
	return (0);
}

int	key_handler_press(int key_code, t_info *info)
{
	if (key_code == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (key_code == KEY_W)
		info->input[INPUT_W] = 1;
	else if (key_code == KEY_S)
		info->input[INPUT_S] = 1;
	else if (key_code == KEY_A)
		info->input[INPUT_A] = 1;
	else if (key_code == KEY_D)
		info->input[INPUT_D] = 1;
	else if (key_code == KEY_RIGHT)
		info->input[INPUT_RIGHT] = 1;
	else if (key_code == KEY_LEFT)
		info->input[INPUT_LEFT] = 1;
	return (0);
}

int	key_handler_release(int key_code, t_info *info)
{
	if (key_code == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (key_code == KEY_W)
		info->input[INPUT_W] = 0;
	else if (key_code == KEY_S)
		info->input[INPUT_S] = 0;
	else if (key_code == KEY_A)
		info->input[INPUT_A] = 0;
	else if (key_code == KEY_D)
		info->input[INPUT_D] = 0;
	else if (key_code == KEY_RIGHT)
		info->input[INPUT_RIGHT] = 0;
	else if (key_code == KEY_LEFT)
		info->input[INPUT_LEFT] = 0;
	return (0);
}