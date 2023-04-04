/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:00:12 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/04 18:52:08 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	int		fd;

	if (argc != 2)
		return (-1);
	//1. 에러 체크
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nOpen error\n", 2);
		return (ERROR);
	}
	type_parse(&info, fd);
	//3. 맵 그리기
	//4. mlx_hook
	//5. 실행
	return (0);
}
