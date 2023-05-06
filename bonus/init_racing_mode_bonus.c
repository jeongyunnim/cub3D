/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_racing_mode_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:10:42 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/06 16:55:12 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int init_racing_mode(t_info *info)
{
    // int i;
    printf("racing_mode_start");
	info->mbase.map.x = info->racing_init.x;
	info->mbase.map.y = info->racing_init.y;
	info->mbase.pos.x = info->mbase.map.x + 0.5;
	info->mbase.pos.y = info->mbase.map.y + 0.5;
    info->racing_flag = 1;
	init_dir(&info->mbase, 1, 0);
    // i = 0;
    // mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen_notice.img, 0, 0);
    // mlx_string_put(info->mlx, info->win_mlx, SCREEN_W / 2, SCREEN_H / 2, 0xfff, "종료: esc\n가속: W\n회전: <및 >\n목표: 연료가 모두 소진 되기 전 goal에 도달하라!");
    return (0);
}