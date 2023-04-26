/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:36:00 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/26 19:29:24 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_argument(int argc, char *argument)
{
	int	len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nArgument count error\n", 2);
		return (ERROR);
	}
	len = ft_strlen(argument);
	if (argument[len - 4] != '.' || argument[len - 3] != 'c' || \
		argument[len - 2] != 'u' || argument[len - 1] != 'b')
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (ERROR);
	}
	return (0);
}
