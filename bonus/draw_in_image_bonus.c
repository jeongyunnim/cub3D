/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:18 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/26 21:34:46 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_in_image(t_img *img, int x, int y, int color)
{
	char	*target;
	int		offset;

	offset = (y * img->line_length + x \
		* (img->bits_per_pixel / 8));
	target = img->addr + offset;
	*(unsigned int *)target = color;
}
