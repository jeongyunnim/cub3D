/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:56:51 by suhkim            #+#    #+#             */
/*   Updated: 2023/04/01 21:52:47 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1024

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*pre;
	char			*str;
	int				fd;
}	t_list;

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	lst_del(t_list *lst);

t_list	*check_fd(t_list *head, int fd);
char	*get_next_line(int fd);
char	*get_one_line(char *str);
char	*read_fd(t_list *node);
char	*remain_line(t_list *node);
#endif
