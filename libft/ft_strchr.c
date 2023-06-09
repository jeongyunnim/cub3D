/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:23:58 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/04 18:23:20 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *)str);
		str++;
	}
	if (*str == (char) c)
		return ((char *)str);
	return (0);
}
