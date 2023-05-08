/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 04:35:17 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 18:21:40 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_xpm_img(t_info *info, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(info->mlx, \
		file, &img->width, &img->height);
	if (img->img == NULL)
		return (ERROR);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (img->addr == NULL)
		return (ERROR);
	return (0);
}

int	init_textures(t_info *info)
{
	if (init_xpm_img(info, &info->textures[N_SIDE], info->north) == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &info->textures[E_SIDE], info->east) == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &info->textures[S_SIDE], info->south) == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &info->textures[W_SIDE], info->west) == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &info->textures[D_SIDE], "asset/door.xpm") == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &info->textures[B_SIDE], \
						"asset/illusion.xpm") == ERROR)
		return (ERROR);
	if (init_xpm_img(info, &info->textures[G_SIDE], "asset/goal.xpm") == ERROR)
		return (ERROR);
	if (init_handle_img(info) == ERROR)
		return (ERROR);
	if (init_notice_img(info) == ERROR)
		return (ERROR);
	if (init_fuel_img(info) == ERROR)
		return (ERROR);
	return (0);
}

int	init_img(t_img *img, void *mlx, int width, int height)
{
	img->img = mlx_new_image(mlx, width, height);
	if (img->img == NULL)
		return (put_error("Error\nmlx_new_image() error\n"));
	img->addr = mlx_get_data_addr(img->img, \
			&img->bits_per_pixel, &img->line_length, \
			&img->endian);
	if (img->addr == NULL)
		return (put_error("Error\nmlx_get_data_addr() error\n"));
	return (0);
}
