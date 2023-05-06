/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handle_img_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:09:03 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/05 18:48:25 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_handle_address(t_img img[5])
{
	img[0].addr = mlx_get_data_addr \
	(img[0].img, &img[0].bits_per_pixel, &img[0].line_length, &img[0].endian);
	if (img[0].addr == NULL)
		return (ERROR);
	img[1].addr = mlx_get_data_addr \
	(img[1].img, &img[1].bits_per_pixel, &img[1].line_length, &img[1].endian);
	if (img[1].addr == NULL)
		return (ERROR);
	img[2].addr = mlx_get_data_addr \
	(img[2].img, &img[2].bits_per_pixel, &img[2].line_length, &img[2].endian);
	if (img[2].addr == NULL)
		return (ERROR);
	img[3].addr = mlx_get_data_addr \
	(img[3].img, &img[3].bits_per_pixel, &img[3].line_length, &img[3].endian);
	if (img[3].addr == NULL)
		return (ERROR);
	img[4].addr = mlx_get_data_addr \
	(img[4].img, &img[4].bits_per_pixel, &img[4].line_length, &img[4].endian);
	if (img[4].addr == NULL)
		return (ERROR);
	return (0);
}

void	draw_handle(t_info *info, t_img *xpm, int size, int i)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			color = *((unsigned int *)(xpm->addr) + \
			((int)(y * (300.0 / size))) * 300 + (int)(x * (300.0 / size)));
			draw_in_image(&info->handle[i], x, y, color);
			x++;
		}
		y++;
	}
}

int	init_handle_img(t_info *info)
{
	int		i;
	int		size;
	t_img	xpm[5];

	xpm[0].img = mlx_xpm_file_to_image(info->mlx, "asset/handle_1.xpm", &i, &i);
	xpm[1].img = mlx_xpm_file_to_image(info->mlx, "asset/handle_2.xpm", &i, &i);
	xpm[2].img = mlx_xpm_file_to_image(info->mlx, "asset/handle_3.xpm", &i, &i);
	xpm[3].img = mlx_xpm_file_to_image(info->mlx, "asset/handle_4.xpm", &i, &i);
	xpm[4].img = mlx_xpm_file_to_image(info->mlx, "asset/handle_5.xpm", &i, &i);
	get_handle_address(xpm);
	i = 0;
	size = SCREEN_W / 6 * 5;
	while (i < 5)
	{
		if (init_img(&info->handle[i], info->mlx, size, size) == ERROR)
			return (ERROR);
		draw_handle(info, &xpm[i], size, i);
		mlx_destroy_image(info->mlx, xpm[i].img);
		i++;
	}
	info->handle_flag = 2;
	return (0);
}