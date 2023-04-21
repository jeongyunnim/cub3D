/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:00:12 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/21 22:11:40 by jeseo            ###   ########.fr       */
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

	info.textures[0].img = mlx_xpm_file_to_image(info.mlx, info.north, &temp, &temp);
	info.textures[1].img = mlx_xpm_file_to_image(info.mlx, info.south, &temp, &temp);
	info.textures[2].img = mlx_xpm_file_to_image(info.mlx, info.west, &temp, &temp);
	info.textures[3].img = mlx_xpm_file_to_image(info.mlx, info.east, &temp, &temp);
	info.textures[0].addr = mlx_get_data_addr(info.textures[0].img, &info.textures[0].bits_per_pixel, &info.textures[0].line_length, &info.textures[0].endian);
	info.textures[1].addr = mlx_get_data_addr(info.textures[1].img, &info.textures[1].bits_per_pixel, &info.textures[1].line_length, &info.textures[1].endian);
	info.textures[2].addr = mlx_get_data_addr(info.textures[2].img, &info.textures[2].bits_per_pixel, &info.textures[2].line_length, &info.textures[2].endian);
	info.textures[3].addr = mlx_get_data_addr(info.textures[3].img, &info.textures[3].bits_per_pixel, &info.textures[3].line_length, &info.textures[3].endian);
	

	draw_map(&info);
	print_image(&info);
	mlx_loop_hook(info.mlx, print_image, &info);
	mlx_hook(info.win_mlx, 02, 0, key_handler, &info);
	mlx_loop(info.mlx);
	return (0);
}
