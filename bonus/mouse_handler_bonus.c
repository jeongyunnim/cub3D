/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:14:28 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 20:11:18 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_handler(int x, int y, t_info *info)
{
	static int	flag;

	if (info->flag.racing == 1)
		return (0);
	if (y == 0)
		y += 1;
	if (x > SCREEN_W / 5 * 4)
	{
		set_inputs(&info->input[INPUT_LEFT], &info->input[INPUT_RIGHT], 0, 1);
		flag = 1;
	}
	else if (x < SCREEN_W / 5)
	{
		set_inputs(&info->input[INPUT_RIGHT], &info->input[INPUT_LEFT], 0, 1);
		flag = 1;
	}
	else if (flag == 1)
	{
		set_inputs(&info->input[INPUT_RIGHT], &info->input[INPUT_LEFT], 0, 0);
		flag = 0;
	}
	return (0);
}
