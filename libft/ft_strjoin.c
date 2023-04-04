/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:42:08 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/04 18:27:39 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = 0;
	while (*(s1 + s1_len))
		s1_len++;
	s2_len = 0;
	while (*(s2 + s2_len))
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	free(s1);
	return (str);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	size_t	s1_len;
//	size_t	s2_len;
//	char	*res;

//	if (s1 == 0 || s2 == 0)
//		return (NULL);
//	s1_len = ft_strlen(s1);
//	s2_len = ft_strlen(s2);
//	res = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
//	ft_memmove(res, s1, s1_len);
//	ft_memmove(res + s1_len, s2, s2_len);
//	return (res);
//}
