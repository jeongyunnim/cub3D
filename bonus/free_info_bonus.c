/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:12:20 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 22:09:12 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_info_screen(t_info *info)
{
	if (info->screen.full.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.full.img);
	if (info->screen.notice.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.notice.img);
	if (info->screen.game_clear.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.game_clear.img);
	if (info->screen.game_over.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.game_over.img);
	if (info->screen.mini_map.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.mini_map.img);
	if (info->screen.current.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.current.img);
	if (info->screen.fuel.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.fuel.img);
	if (info->screen.fuel_bar.img != NULL)
		mlx_destroy_image(info->mlx, info->screen.fuel_bar.img);
}

void	free_info_img(t_info *info)
{
	int	i;

	free_info_screen(info);
	i = 0;
	while (i < 7)
	{
		if (info->textures[i].img != NULL)
			mlx_destroy_image(info->mlx, info->textures[i].img);
		if (i < 5 && info->handle[i].img != NULL)
			mlx_destroy_image(info->mlx, info->handle[i].img);
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
