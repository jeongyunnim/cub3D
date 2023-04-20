/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:51:09 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/20 16:20:31 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_plane(t_dpos *plane, double x, double y)
{
	plane->x = x;
	plane->y = y;
}

void	init_dir(t_mbase *mbase, double x, double y)
{
	mbase->dir.x = x;
	mbase->dir.y = y;
	if (x == 1 || y == 1)
		init_plane(&mbase->plane, 0.66 * (1 - (x * 2)), 0);
	else
		init_plane(&mbase->plane, 0, 0.66 * (1 - (fabs(y) * 2)));
	printf("%f %f %f %f\n", mbase->dir.x, mbase->dir.y , mbase->plane.x , mbase->plane.y);
}

void	init_pos(t_mbase *mbase, int i, int j)
{
	mbase->map.x = j;
	mbase->map.y = i;
	mbase->pos.x = mbase->map.x + 0.5;
	mbase->pos.y = mbase->map.y + 0.5;
}

void	init_map_base(t_info *info, t_mbase *mbase)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j] != '0' && info->map[i][j] != '1' && info->map[i][j] != ' ')
			{
				init_pos(mbase, i, j);
				if (info->map[i][j] == 'N')
					init_dir(mbase, 0, 1);
				else if (info->map[i][j] == 'E')
					init_dir(mbase, 1, 0);
				else if (info->map[i][j] == 'S')
					init_dir(mbase, 0, -1);
				else
					init_dir(mbase, -1, 0);
			}
			j++;
		}
		i++;
	}
	mbase->move_speed = 0.1;
	mbase->rot_speed = 0.1;
}

int	init_info(t_info *info)
{
	ft_memset(info, 0, sizeof(t_info));
	info->mlx = mlx_init();
	if (info->mlx == NULL)
	{
		ft_putstr_fd("Error\nmlx_init() error\n", 2);
		return (ERROR);
	}
	info->win_mlx = mlx_new_window(info->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (info->win_mlx == NULL)
	{
		ft_putstr_fd("Error\nmlx_new_window() error\n", 2);
		return (ERROR);
	}
	info->screen.img = mlx_new_image(info->mlx, SCREEN_W, SCREEN_H);
	if (info->screen.img == NULL)
	{
		ft_putstr_fd("Error\nmlx_new_image() error\n", 2);
		return (ERROR);
	}
	info->screen.addr = mlx_get_data_addr(info->screen.img, &info->screen.bits_per_pixel, &info->screen.line_length, &info->screen.endian);
	if (info->screen.addr == NULL)
	{
		ft_putstr_fd("Error\nmlx_get_data_addr() error\n", 2);
		return (ERROR);
	}
	return (0);
}