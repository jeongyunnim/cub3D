/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:58:04 by suhkim            #+#    #+#             */
/*   Updated: 2023/05/08 21:48:07 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_error(t_info *info, char *str)
{
	ft_putstr_fd(str, 2);
	free_info(info);
	return (ERROR);
}

int	exit_put_error(t_info *info, char *str)
{
	ft_putstr_fd(str, 2);
	free_info(info);
	exit(EXIT_FAILURE);
}
