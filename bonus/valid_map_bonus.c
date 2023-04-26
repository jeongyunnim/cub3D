/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:05:30 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/26 19:29:33 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	valid_map(t_info *info)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' \
					|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
	{
		ft_putstr_fd("Error\nPlayer location is invalid\n", 2);
		return (ERROR);
	}
	return (0);
}
