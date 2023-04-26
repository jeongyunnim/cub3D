/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 04:35:17 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/24 04:47:46 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_img_address(t_info *info)
{
	info->textures[N_SIDE].addr = mlx_get_data_addr \
	(info->textures[N_SIDE].img, &info->textures[N_SIDE].bits_per_pixel, \
	&info->textures[N_SIDE].line_length, &info->textures[N_SIDE].endian);
	if (info->textures[N_SIDE].addr == NULL)
		return (ERROR);
	info->textures[S_SIDE].addr = mlx_get_data_addr \
	(info->textures[S_SIDE].img, &info->textures[S_SIDE].bits_per_pixel, \
	&info->textures[S_SIDE].line_length, &info->textures[S_SIDE].endian);
	if (info->textures[S_SIDE].addr == NULL)
		return (ERROR);
	info->textures[W_SIDE].addr = mlx_get_data_addr \
	(info->textures[W_SIDE].img, &info->textures[W_SIDE].bits_per_pixel, \
	&info->textures[W_SIDE].line_length, &info->textures[W_SIDE].endian);
	if (info->textures[W_SIDE].addr == NULL)
		return (ERROR);
	info->textures[E_SIDE].addr = mlx_get_data_addr \
	(info->textures[E_SIDE].img, &info->textures[E_SIDE].bits_per_pixel, \
	&info->textures[E_SIDE].line_length, &info->textures[E_SIDE].endian);
	if (info->textures[E_SIDE].addr == NULL)
		return (ERROR);
	return (0);
}

int	init_img(t_info *info)
{
	int	temp;

	info->textures[N_SIDE].img = \
		mlx_xpm_file_to_image(info->mlx, info->north, &temp, &temp);
	if (info->textures[N_SIDE].img == NULL)
		return (ERROR);
	info->textures[S_SIDE].img = \
		mlx_xpm_file_to_image(info->mlx, info->south, &temp, &temp);
	if (info->textures[S_SIDE].img == NULL)
		return (ERROR);
	info->textures[W_SIDE].img = \
		mlx_xpm_file_to_image(info->mlx, info->west, &temp, &temp);
	if (info->textures[W_SIDE].img == NULL)
		return (ERROR);
	info->textures[E_SIDE].img = \
		mlx_xpm_file_to_image(info->mlx, info->east, &temp, &temp);
	if (info->textures[E_SIDE].img == NULL)
		return (ERROR);
	return (0);
}
