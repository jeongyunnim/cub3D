/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:43:52 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/10 17:24:56 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_inputs(int *target1, int *target2, int value1, int value2)
{
	*target1 = value1;
	*target2 = value2;
}

static void	racing_mode_input(t_info *info, t_update_data *data, int mode)
{
	if (mode == 1)
	{
		input_w(info);
		if (info->flag.accel == 0 && info->mbase.move_speed > 0.01)
			info->mbase.move_speed -= 0.0005;
		else if (info->flag.accel == 1 && info->mbase.move_speed < 0.4)
			info->mbase.move_speed += 0.00005;
	}
	else
	{
		if (info->input[INPUT_W] == 1)
			input_w(info);
		if (info->input[INPUT_S] == 1)
			input_s(info);
		if (info->input[INPUT_A] == 1)
			input_a(info, data);
		if (info->input[INPUT_D] == 1)
			input_d(info, data);
	}
}

int	input_update(t_info *info)
{
	t_update_data	data;

	data.old_dir_x = info->mbase.dir.x;
	data.old_plane_x = info->mbase.plane.x;
	if (info->flag.racing == 1)
		racing_mode_input(info, &data, 1);
	else
		racing_mode_input(info, &data, 0);
	if (info->input[INPUT_R] == 1)
		input_right(info, data);
	if (info->input[INPUT_L] == 1)
		input_left(info, data);
	info->mbase.map.x = (int)info->mbase.pos.x;
	info->mbase.map.y = (int)info->mbase.pos.y;
	if (info->flag.wait == 0 && \
		info->map[info->mbase.map.y][info->mbase.map.x] == 'B')
		info->flag.wait = 1;
	if (info->flag.racing && !info->flag.end \
		&& info->map[info->mbase.map.y][info->mbase.map.x] == 'G')
		info->flag.end = SUCCESS;
	draw_map(info);
	return (0);
}

int	key_handler_press(int key_code, t_info *info)
{
	if (key_code == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (!info->flag.wait && key_code == KEY_W)
		set_inputs(&info->input[INPUT_W], &info->flag.accel, 1, 1);
	else if (!info->flag.wait && key_code == KEY_S)
		info->input[INPUT_S] = 1;
	else if (!info->flag.wait && key_code == KEY_A)
		info->input[INPUT_A] = 1;
	else if (!info->flag.wait && key_code == KEY_D)
		info->input[INPUT_D] = 1;
	else if (!info->flag.wait && key_code == KEY_RIGHT)
		set_inputs(&info->input[INPUT_L], &info->input[INPUT_R], 0, 1);
	else if (!info->flag.wait && key_code == KEY_LEFT)
		set_inputs(&info->input[INPUT_R], &info->input[INPUT_L], 0, 1);
	else if (key_code == KEY_SPACE && info->flag.wait == 1)
	{
		info->flag.wait = 0;
		init_racing_mode(info);
	}
	return (0);
}

int	key_handler_release(int key_code, t_info *info)
{
	if (key_code == KEY_W)
		set_inputs(&info->input[INPUT_W], &info->flag.accel, 0, 0);
	else if (key_code == KEY_S)
		info->input[INPUT_S] = 0;
	else if (key_code == KEY_A)
		info->input[INPUT_A] = 0;
	else if (key_code == KEY_D)
		info->input[INPUT_D] = 0;
	else if (key_code == KEY_RIGHT)
		set_inputs(&info->input[INPUT_R], &info->flag.handle, 0, 0);
	else if (key_code == KEY_LEFT)
		set_inputs(&info->input[INPUT_L], &info->flag.handle, 0, 0);
	else if (key_code == KEY_SPACE && is_around_door(info))
		door_update(info, info->mbase.pos.x, info->mbase.pos.y);
	return (0);
}
