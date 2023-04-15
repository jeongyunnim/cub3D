/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:02:15 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/06 21:12:40 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

# define ERROR -1

typedef struct s_map_list
{
	struct s_map_list	*next;
	char				*one_line;
}	t_map_list;

typedef struct s_map_info
{
	int	min_w;
	int	max_w;
	int	height;
}		t_map_info;

typedef enum e_type
{
	NORTH = 0x01,
	SOUTH = 0x02,
	WEST = 0x04,
	EAST = 0x08,
	FLOOR = 0x10,
	CEILING = 0x20,
	TYPE_S = 0x3f
}			t_type;

typedef struct s_info
{
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor[3];
	int		ceiling[3];
	int		flag;
	int		map_width;
	int		map_height;
}				t_info;

/*split_is_function.c */
char		**split_is_function(const char *s, int (*f)(int));

/* parse.c */
int			parse(t_info *info, int fd);

/* type_parse.c */
int			type_parse(t_info *info, int fd);

/* check_argument.c */
int			check_argument(int argc, char *argument);

/* check_closed_map.c */
int			check_closed_map(t_info *info);

/* map_parse.c */
int			map_parse(t_info *info, int fd, char *first_line);

/* map_list_util.c */
t_map_list	*lstnew_map_line(char *one_line);
t_map_list	*pop_map_line_head(t_map_list **head);
void		add_map_line_tail(t_map_list *head, t_map_list *new);

#endif