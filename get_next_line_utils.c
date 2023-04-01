/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:50:33 by suhkim            #+#    #+#             */
/*   Updated: 2022/07/13 22:03:10 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*sptr;
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	sptr = s;
	if (c == 0)
		return ((char *)sptr + len);
	while (*sptr)
	{
		if (*(char *)sptr == (char)c)
			return ((char *)sptr);
		sptr++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*str;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

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

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ;
	while (*(src + i) != '\0')
	{
		if (i == dstsize - 1)
			break ;
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

void	lst_del(t_list	*lst)
{	
	lst->pre->next = lst->next;
	if (lst->next)
		lst->next->pre = lst->pre;
	free(lst);
}
