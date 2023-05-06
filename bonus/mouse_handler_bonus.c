/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:14:28 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/06 20:21:33 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_handler(int x, int y, t_info *info)
{
	static int	flag;

	if (info->racing_flag == 1)
		return (0);
	y += 1;
	if (x > SCREEN_W / 5 * 4)
	{
		info->input[INPUT_LEFT] = 0;
		info->input[INPUT_RIGHT] = 1;
		flag = 1;
	}
	else if (x < SCREEN_W / 5)
	{
		info->input[INPUT_RIGHT] = 0;
		info->input[INPUT_LEFT] = 1;
		flag = 1;
	}
	else
	{
		if (flag == 1)
		{
			info->input[INPUT_RIGHT] = 0;
			info->input[INPUT_LEFT] = 0;
			flag = 0;
		}
	}
	return (0);
}