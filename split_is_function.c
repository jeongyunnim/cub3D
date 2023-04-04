/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_is_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:14:36 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/04 18:56:47 by jeseo            ###   ########.fr       */
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

static char	**free_all(char **carr, int cnt)
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

char	**split_is_function(const char *s, int (*f)(int))
{
	int		cnt;
	char	**carr;

	if (!s)
		return (0);
	cnt = 0;
	carr = (char **)ft_calloc(sizeof(char *), (cnt_word(s, f, 0) + 1));
	while (*s)
	{
		if (!f(*s))
		{
			carr[cnt] = ft_calloc(sizeof(char), (cnt_word(s, f, 1) + 1));
			s += set_words(f, carr[cnt++], s);
		}
		else
			s++;
	}
	return (carr);
}
