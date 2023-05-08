/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:00:12 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/08 21:50:33 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	int		fd;

	if (init_info(&info) == ERROR)
		exit(EXIT_FAILURE);
	if (check_argument(argc, argv[1]) == ERROR)
		exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_put_error(&info, "Error\nOpen error\n");
	if (parse(&info, fd) == ERROR || valid_map(&info) == ERROR)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	init_map_base(&info, &info.mbase);
	if (init_img(&info) == ERROR || get_img_address(&info) == ERROR)
		exit_put_error(&info, "Error\nTexture file error\n");
	mlx_loop_hook(info.mlx, main_loop, &info);
	mlx_hook(info.win_mlx, 02, 0, key_handler_press, &info);
	mlx_hook(info.win_mlx, 03, 0, key_handler_release, &info);
	mlx_hook(info.win_mlx, 17, 0, destroy_handler, NULL);
	mlx_loop(info.mlx);
	return (0);
}
