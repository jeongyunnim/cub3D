/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_racing_mode_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:10:42 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/10 17:01:23 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_racing_mode(t_info *info)
{
	info->flag.racing = 1;
	info->flag.notice = 1;
	info->mbase.map.x = info->racing_init.x;
	info->mbase.map.y = info->racing_init.y;
	info->mbase.pos.x = info->mbase.map.x + 0.5;
	info->racing_start = info->mbase.map.x + 0.5;
	info->mbase.pos.y = info->mbase.map.y + 0.5;
	info->flag.handle = 0;
	init_dir(&info->mbase, 1, 0);
	return (0);
}
