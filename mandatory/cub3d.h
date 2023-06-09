/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:02:15 by jeseo             #+#    #+#             */
/*   Updated: 2023/05/10 17:24:54 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define ERROR -1
# define SCREEN_W 1920 // FULL HD
# define SCREEN_H 1080
# define TEX_W 64
# define TEX_H 64

typedef enum e_side
{
	N_SIDE,
	S_SIDE,
	E_SIDE,
	W_SIDE
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
	KEY_W=13,
	KEY_S=1,
	KEY_A=0,
	KEY_D=2,
	KEY_ESC=53,
}			t_key;

typedef enum e_input
{
	INPUT_L,
	INPUT_R,
	INPUT_W,
	INPUT_S,
	INPUT_A,
	INPUT_D,
}			t_input;

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
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	double			step;
	double			pos;
	int				x;
	int				y;
	unsigned int	color;
	int				col;
	int				camera_x;
}				t_tex;

typedef struct s_update_data
{
	double	old_dir_x;
	double	old_plane_x;
	double	side_walk_x;
	double	side_walk_y;
}	t_update_data;

typedef struct s_info
{
	t_mbase	mbase;
	t_img	screen;
	t_img	textures[4];
	int		input[6];
	void	*mlx;
	void	*win_mlx;
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

/* type_parse_utils.c */
int			rgb_valid_check(char **rgb, int target[3]);
int			error_flag_check(t_info *info, char **rgb, char **type);
void		free_two_dimension_array(char **arr);
int			init_rgb(t_info *info, char **type);
int			type_init(t_info *info, char **type);

/* check_argument.c */
int			check_argument(int argc, char *argument);

/* check_closed_map.c */
int			check_closed_map(t_info *info);

/* map_parse.c */
int			map_parse(t_info *info, int fd, char *first_line);

/* map_parse_utils.c */
int			check_valid_value_idx(t_map_info *map, \
								char *line, int i, int *flag);
int			check_map_one_line(char *line, t_map_info *map);
int			check_all_line(t_map_info *map_info, t_map_list *temp);
void		define_map_size(t_info *info, t_map_info *map_info, \
							t_map_list *temp);
void		free_map_list(t_map_list *target);

/* map_list_util.c */
t_map_list	*lstnew_map_line(char *one_line);
t_map_list	*pop_map_line_head(t_map_list **head);
void		add_map_line_tail(t_map_list *head, t_map_list *new);

/* draw_map.c */
int			draw_map(t_info *info);

/* draw_one_line.c */
int			draw_one_line(t_info *info, t_mbase *mbase, t_ray *ray, int i);

/* init.c */
void		init_map_base(t_info *info, t_mbase *mbase);
int			init_info(t_info *info);

/* cal_perp_dist.c */
void		cal_perp_dist(t_info *info, t_mbase *mbase, t_ray *ray, double c);

/* dda.c */
double		dda(t_info *info, t_mbase mbase, t_ray *ray);

/* valid_map.c */
int			valid_map(t_info *info);

/* key_handler.c */
int			key_handler(int key_code, t_info *info);
int			key_handler_press(int key_code, t_info *info);
int			key_handler_release(int key_code, t_info *info);
int			input_update(t_info *info);

/* input_wasd.c */
void		input_w(t_info *info);
void		input_s(t_info *info);
void		input_a(t_info *info, t_update_data data);
void		input_d(t_info *info, t_update_data data);

/* input_right_left.c */
void		input_right(t_info *info, t_update_data data);
void		input_left(t_info *info, t_update_data data);

/* draw_in_image.c */
void		draw_in_image(t_info *info, int x, int y, int color);

/* print_image.c */
int			print_image(t_info *info);
int			main_loop(t_info *info);

/* put_error.c */
int			put_error(t_info *info, char *str);
int			exit_put_error(t_info *info, char *str);

/* init_img.c */
int			init_img(t_info *info);
int			get_img_address(t_info *info);

/* destroy_handler.c */
int			destroy_handler(void);

/* free_info.c */
void		free_info(t_info *info);

#endif
