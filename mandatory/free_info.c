/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:12:20 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 21:50:47 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_info_img(t_info *info)
{
	int	i;

	if (info->screen.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.img);
	i = 0;
	while (i < 4)
	{
		if (info->textures[i].img != NULL)
			mlx_destroy_image(info->mlx, info->textures[i].img);
		i++;
	}
	if (info->win_mlx != NULL)
		mlx_destroy_window(info->mlx, info->win_mlx);
}

void	free_info(t_info *info)
{
	int	i;

	if (info->map != NULL)
	{
		i = 0;
		while (i < info->map_height)
		{
			free(info->map[i]);
			i++;
		}
		free(info->map);
	}
	if (info->north != NULL)
		free(info->north);
	if (info->south != NULL)
		free(info->south);
	if (info->east != NULL)
		free(info->east);
	if (info->west != NULL)
		free(info->west);
	free_info_img(info);
}
