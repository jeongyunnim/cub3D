/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:51:09 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/17 20:56:59 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dir(t_dpos *dir, double x, double y)
{
	dir->x = x;
	dir->y = y;
}

void	init_plane(t_dpos *plane, double x, double y)
{
	plane->x = x;
	plane->y = y;
}

void	init_map_base(t_info *info, t_mbase *mbase)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j] != '0' && info->map[i][j] != '1' && info->map[i][j] != ' ')
			{
				mbase->map.x = j;
				mbase->map.y = i;
				mbase->pos.x = mbase->map.x + 0.5;
				mbase->pos.y = mbase->map.y + 0.5;
				if (info->map[i][j] == 'N')
				{
					init_dir(&mbase->dir, 0, 1);
					init_plane(&mbase->plane, 0.66, 0);
				}
				else if (info->map[i][j] == 'E')
				{
					init_dir(&mbase->dir, 1, 0);
					init_plane(&mbase->plane, -0.66, 0);
				}
				else if (info->map[i][j] == 'S')
				{
					init_dir(&mbase->dir, 0, -1);
					init_plane(&mbase->plane, 0, -0.66);
				}
				else
				{
					init_dir(&mbase->dir, -1, 0);
					init_plane(&mbase->plane, 0, 0.66);
				}
			}
			j++;
		}
		i++;
	}
}
