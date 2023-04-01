/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:14:36 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/01 21:48:56 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cnt_word(const char *s, int (*f)(int), int mode)
{
	int	cnt;
	int	words;

	words = 1;
	cnt = 0;
	while (*s)
	{
		if (!f(*s) && (*(s + 1) == 0 || f(*(s + 1))))
		{
			cnt++;
			if (*(s + 1) == 0 && mode == 0)
				return (cnt);
			if (mode)
				return (words);
		}
		words++;
		s++;
	}
	return (cnt);
}

static char	**freeall(char **carr, int cnt)
{
	while (cnt--)
		free(carr[cnt]);
	free(carr);
	return (0);
}

static int	set_words(int (*f)(int), char *set, const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) && !f(*(s + i)))
	{
		*(set + i) = *(s + i);
		i++;
	}
	*(set + i) = 0;
	return (i);
}

char	**ft_split(const char *s, int (*f)(int))
{
	int		cnt;
	char	**carr;

	if (!s)
		return (0);
	cnt = 0;
	carr = (char **)malloc(sizeof(char *) * (cnt_word(s, f, 0) + 1));
	if (!carr)
		return (0);
	while (*s)
	{
		if (!f(*s))
		{
			carr[cnt] = (char *)malloc(sizeof(char) * (cnt_word(s, f, 1) + 1));
			if (!carr[cnt])
				return (freeall(carr, cnt));
			s += set_words(f, carr[cnt++], s);
		}
		else
			s++;
	}
	carr[cnt] = 0;
	return (carr);
}
