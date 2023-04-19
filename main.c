/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:00:12 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/19 20:55:17 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	int		fd;

	if (init_info(&info) == ERROR)
		return (ERROR);
	if (check_argument(argc, argv[1]) == ERROR)
		return (ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nOpen error\n", 2);
		return (ERROR);
	}
	if (parse(&info, fd) == ERROR || valid_map(&info) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	init_map_base(&info, &info.mbase);
	mlx_loop_hook(info.mlx, draw_map, &info);
	mlx_hook(info.win_mlx, 02, 0, key_handler, &info);
	mlx_loop(info.mlx);
	//5. 실행
	return (0);
}
