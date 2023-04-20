/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:21 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/20 17:08:45 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_image(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win_mlx, info->screen.img, 0, 0);
	return (0);
}