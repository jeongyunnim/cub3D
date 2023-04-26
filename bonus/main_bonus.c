/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:00:12 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/26 21:56:14 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		return (put_error("Error\nOpen error\n"));
	if (parse(&info, fd) == ERROR || valid_map(&info) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	init_map_base(&info, &info.mbase);
	if (init_img(&info) == ERROR || get_img_address(&info) == ERROR)
		return (put_error("Error\nTexture file error\n"));

	info.mini_map.img = mlx_new_image(info.mlx, SCREEN_W, SCREEN_H);
	if (info.mini_map.img == NULL)
		return (put_error("Error\nmlx_new_image() error\n"));
	info.mini_map.addr = mlx_get_data_addr(info.mini_map.img, \
			&info.mini_map.bits_per_pixel, &info.mini_map.line_length, \
			&info.mini_map.endian);
	if (info.mini_map.addr == NULL)
		return (put_error("Error\nmlx_get_data_addr() error\n"));


	mlx_loop_hook(info.mlx, main_loop, &info);
	mlx_hook(info.win_mlx, 02, 0, key_handler_press, &info);
	mlx_hook(info.win_mlx, 03, 0, key_handler_release, &info);
	mlx_hook(info.win_mlx, 06, 0, mouse_handler, &info);
	mlx_hook(info.win_mlx, 17, 0, destroy_handler, NULL);
	mlx_loop(info.mlx);
	return (0);
}
