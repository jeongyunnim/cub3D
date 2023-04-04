/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:33:18 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/04 18:35:13 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	if (dest == NULL || src == NULL || dest_size == 0)
		return (0);
	src_size = ft_strlen(src);
	while (src[i] != '\0' && i + 1 < dest_size)
	{
		dest[i] = src[i];
		i++;
	}
	if (dest_size > 0)
		dest[i] = '\0';
	return (src_size);
}

//겟넥라 보험용
//void	ft_strlcpy(char *dst, char *src, size_t dstsize)
//{
//	size_t	i;

//	i = 0;
//	if (dstsize == 0)
//		return ;
//	while (*(src + i) != '\0')
//	{
//		if (i == dstsize - 1)
//			break ;
//		*(dst + i) = *(src + i);
//		i++;
//	}
//	*(dst + i) = '\0';
//}