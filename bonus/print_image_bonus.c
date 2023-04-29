/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/28 21:37:22 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	print_image(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->mini_map.img, 0, 0);
	return (0);
}

int	main_loop(t_info *info)
{
	print_image(info);
	input_update(info);
	return (0);
}
