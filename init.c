/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:51:09 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/15 22:08:42 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_base(t_info *info, t_mbase *mbase)
{
	int	i;

	i = 0;
	while (i < info->map_height * info->map_width)
	{
		if (*(info->map + i) != '0' && *(info->map + i) != '1' && *(info->map + i) != ' ')
		{
			mbase->map.x = i / info->map_width;
			mbase->map.y = i % info->map_width;
			//mbase 처리해주기.
		}
		i++;
	}
}
