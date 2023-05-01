/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_wasd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:04:33 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/01 22:07:31 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_available_move(t_info *info, double x, double y)
{
	double	margin;

	margin = 0.05;
	if (info->map[(int)y][(int)x] == '1')
		return (0);
	else if (info->map[(int)(y + margin)][(int)x] == '1')
		return (0);
	else if (info->map[(int)y][(int)(x + margin)] == '1')
		return (0);
	else if (info->map[(int)(y + margin)][(int)(x + margin)] == '1')
		return (0);
	else if (info->map[(int)(y - margin)][(int)x] == '1')
		return (0);
	else if (info->map[(int)y][(int)(x - margin)] == '1')
		return (0);
	else if (info->map[(int)(y - margin)][(int)(x - margin)] == '1')
		return (0);
	else if (info->map[(int)(y - margin)][(int)(x + margin)] == '1')
		return (0);
	else if (info->map[(int)(y + margin)][(int)(x - margin)] == '1')
		return (0);
	return (1);
}

void	input_w(t_info *info)
{
	if (is_available_move(info, info->mbase.pos.x + info->mbase.dir.x \
		* info->mbase.move_speed, info->mbase.pos.y) && !is_around_D(info, \
			 info->mbase.pos.x + info->mbase.dir.x \
		* info->mbase.move_speed, info->mbase.pos.y))
		info->mbase.pos.x += info->mbase.dir.x * info->mbase.move_speed;
	if (is_available_move(info, info->mbase.pos.x, info->mbase.pos.y \
		+ info->mbase.dir.y * info->mbase.move_speed) && !is_around_D(info, \
			info->mbase.pos.x, info->mbase.pos.y \
		+ info->mbase.dir.y * info->mbase.move_speed))
		info->mbase.pos.y += info->mbase.dir.y * info->mbase.move_speed;
}

void	input_s(t_info *info)
{
	if (is_available_move(info, info->mbase.pos.x \
			- info->mbase.dir.x * info->mbase.move_speed, info->mbase.pos.y) \
			&& !is_around_D(info, info->mbase.pos.x \
			- info->mbase.dir.x * info->mbase.move_speed, info->mbase.pos.y))
		info->mbase.pos.x -= info->mbase.dir.x * info->mbase.move_speed;
	if (is_available_move(info, info->mbase.pos.x, info->mbase.pos.y \
	- info->mbase.dir.y * info->mbase.move_speed) && !is_around_D(info, \
		info->mbase.pos.x, info->mbase.pos.y - info->mbase.dir.y * \
		info->mbase.move_speed))
		info->mbase.pos.y -= info->mbase.dir.y * info->mbase.move_speed;
}

void	input_a(t_info *info, t_update_data data)
{
	data.side_walk_x = info->mbase.dir.x * cos(acos(-1) / 2) \
					- info->mbase.dir.y * sin(acos(-1) / 2);
	data.side_walk_y = data.old_dir_x * sin(acos(-1) / 2) \
					+ info->mbase.dir.y * cos(acos(-1) / 2);
	if (is_available_move(info, info->mbase.pos.x \
			+ data.side_walk_x * info->mbase.move_speed, info->mbase.pos.y) \
			&& !is_around_D(info, info->mbase.pos.x \
			+ data.side_walk_x * info->mbase.move_speed, info->mbase.pos.y))
		info->mbase.pos.x += data.side_walk_x * info->mbase.move_speed;
	if (is_available_move(info, info->mbase.pos.x, info->mbase.pos.y \
	+ data.side_walk_y * info->mbase.move_speed) && !is_around_D(info, \
		info->mbase.pos.x, info->mbase.pos.y + data.side_walk_y * \
		info->mbase.move_speed))
		info->mbase.pos.y += data.side_walk_y * info->mbase.move_speed;
}

void	input_d(t_info *info, t_update_data data)
{
	data.side_walk_x = info->mbase.dir.x * cos(acos(-1) / 2) \
					- info->mbase.dir.y * sin(acos(-1) / 2);
	data.side_walk_y = data.old_dir_x * sin(acos(-1) / 2) \
					+ info->mbase.dir.y * cos(acos(-1) / 2);
	if (is_available_move(info, info->mbase.pos.x \
			- data.side_walk_x * info->mbase.move_speed, info->mbase.pos.y) \
		&& !is_around_D(info, info->mbase.pos.x \
			- data.side_walk_x * info->mbase.move_speed, info->mbase.pos.y))
		info->mbase.pos.x -= data.side_walk_x * info->mbase.move_speed;
	if (is_available_move(info, info->mbase.pos.x, info->mbase.pos.y \
	- data.side_walk_y * info->mbase.move_speed) && !is_around_D(info, \
		info->mbase.pos.x, info->mbase.pos.y - data.side_walk_y * \
		info->mbase.move_speed))
		info->mbase.pos.y -= data.side_walk_y * info->mbase.move_speed;
}
