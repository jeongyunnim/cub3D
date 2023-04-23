/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:00:12 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/23 19:42:09 by jeseo            ###   ########.fr       */
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

	int temp;

	info.textures[N_SIDE].img = mlx_xpm_file_to_image(info.mlx, info.north, &temp, &temp);
	info.textures[S_SIDE].img = mlx_xpm_file_to_image(info.mlx, info.south, &temp, &temp);
	info.textures[W_SIDE].img = mlx_xpm_file_to_image(info.mlx, info.west, &temp, &temp);
	info.textures[E_SIDE].img = mlx_xpm_file_to_image(info.mlx, info.east, &temp, &temp);
	info.textures[N_SIDE].addr = mlx_get_data_addr(info.textures[N_SIDE].img, &info.textures[N_SIDE].bits_per_pixel, &info.textures[N_SIDE].line_length, &info.textures[N_SIDE].endian);
	info.textures[S_SIDE].addr = mlx_get_data_addr(info.textures[S_SIDE].img, &info.textures[S_SIDE].bits_per_pixel, &info.textures[S_SIDE].line_length, &info.textures[S_SIDE].endian);
	info.textures[W_SIDE].addr = mlx_get_data_addr(info.textures[W_SIDE].img, &info.textures[W_SIDE].bits_per_pixel, &info.textures[W_SIDE].line_length, &info.textures[W_SIDE].endian);
	info.textures[E_SIDE].addr = mlx_get_data_addr(info.textures[E_SIDE].img, &info.textures[E_SIDE].bits_per_pixel, &info.textures[E_SIDE].line_length, &info.textures[E_SIDE].endian);

	draw_map(&info);
	print_image(&info);
	mlx_loop_hook(info.mlx, print_image, &info);
	mlx_hook(info.win_mlx, 02, 0, key_handler, &info);
	mlx_loop(info.mlx);
	return (0);
}
