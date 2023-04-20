/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:02:15 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/20 15:56:11 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define ERROR -1
# define SCREEN_W 1920
# define SCREEN_H 1080

typedef	enum e_side
{
	N_SIDE=0x00ff0000,
	S_SIDE=0x00ffff00,
	E_SIDE=0x0000ff00,
	W_SIDE=0x000000ff,
	C_SIDE=0x00555555,
	F_SIDE=0x00ffffff
}	t_side;

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

typedef enum e_key
{
	KEY_LEFT=123,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_UP,
	KEY_ESC=53,
}			t_key;

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

typedef struct s_int_pos
{
	int	x;
	int	y;
}	t_ipos;

typedef struct s_double_pos
{
	double	x;
	double	y;
}	t_dpos;

typedef struct s_map_base
{
	t_ipos	map;
	t_dpos	pos;
	t_dpos	dir;
	t_dpos	plane;
	double	move_speed;
	double	rot_speed;
}	t_mbase;

typedef struct s_ray
{
	t_dpos	dir;
	t_dpos	delta_dist;
	t_dpos	side_dist;
	t_ipos	step;
	double	perp_dist;
	int		side;
}	t_ray;

typedef struct s_line
{
	int	wall_height;
	int	bottom;
	int	top;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_info
{
	t_mbase	mbase;
	void	*mlx;
	void	*win_mlx;
	t_img	screen;
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

/* draw_map.c */
int			draw_map(t_info *info);

/* draw_one_line.c */
int			draw_one_line(t_info *info, t_mbase *mbase, t_ray ray, int i);

/* init.c */
void		init_map_base(t_info *info, t_mbase *mbase);
int			init_info(t_info *info);

/* cal_perp_dist.c */
void		cal_perp_dist(t_info *info, t_mbase *mbase, t_ray *ray, double camera);

/* dda.c */
double		dda(t_info *info, t_mbase mbase, t_ray *ray);

/* valid_map.c */
int			valid_map(t_info *info);

/* key_handler.c */
int			key_handler(int key_code, t_info *info);

#endif