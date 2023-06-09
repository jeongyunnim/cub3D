/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:43:52 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/10 17:24:55 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input_update(t_info *info)
{
	t_update_data	data;

	data.old_dir_x = info->mbase.dir.x;
	data.old_plane_x = info->mbase.plane.x;
	if (info->input[INPUT_W] == 1)
		input_w(info);
	if (info->input[INPUT_S] == 1)
		input_s(info);
	if (info->input[INPUT_A] == 1)
		input_a(info, data);
	if (info->input[INPUT_D] == 1)
		input_d(info, data);
	if (info->input[INPUT_R] == 1)
		input_right(info, data);
	if (info->input[INPUT_L] == 1)
		input_left(info, data);
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
	{
		info->input[INPUT_L] = 0;
		info->input[INPUT_R] = 1;
	}
	else if (key_code == KEY_LEFT)
	{
		info->input[INPUT_R] = 0;
		info->input[INPUT_L] = 1;
	}
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
		info->input[INPUT_R] = 0;
	else if (key_code == KEY_LEFT)
		info->input[INPUT_L] = 0;
	return (0);
}
