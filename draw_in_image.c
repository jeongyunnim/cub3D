/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:18 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/20 16:35:10 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_in_image(t_info *info, int x, int y, int color)
{
	char	*target;
	int		offset;
	
	offset = (y * info->screen.line_length + x * (info->screen.bits_per_pixel / 8));
	target = info->screen.addr + offset;
	*(unsigned int *)target = color;
}
