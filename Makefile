NAME		=	./cub3D

NAME_B		=	./cub3D_bonus

LIBFTDIR	= ./libft

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror \
# -g3 -fsanitize=address
MLX_FLAGS	=	-framework OpenGL -framework Appkit

INCLUDES 	=	-I ./libft/ \
				-I ./mlx/\
   				-I ./mandatory/

INCLUDES_B 	=	-I ./libft/ \
				-I ./mlx/\
   				-I ./bonus/

LIBS		=	-L ./libft/ -l ft\
				-L ./mlx/ -l mlx

LIBS_B		=	-L ./libft/ -l ft\
				-L ./mlx/ -l mlx

SRCS			=	./mandatory/main.c\
					./mandatory/init.c\
					./mandatory/split_is_function.c\
					./mandatory/map_list_util.c\
					./mandatory/parse.c\
					./mandatory/check_argument.c\
					./mandatory/check_closed_map.c\
					./mandatory/map_parse.c\
					./mandatory/map_parse_utils.c\
					./mandatory/type_parse.c\
					./mandatory/type_parse_utils.c\
					./mandatory/draw_map.c\
					./mandatory/draw_one_line.c\
					./mandatory/draw_in_image.c\
					./mandatory/print_image.c\
					./mandatory/cal_perp_dist.c\
					./mandatory/dda.c\
					./mandatory/valid_map.c\
					./mandatory/key_handler.c\
					./mandatory/input_wasd.c\
					./mandatory/input_right_left.c\
					./mandatory/put_error.c\
					./mandatory/init_img.c\
					./mandatory/destroy_handler.c\

SRCS_B			=	./bonus/main_bonus.c\
					./bonus/init_bonus.c\
					./bonus/split_is_function_bonus.c\
					./bonus/map_list_util_bonus.c\
					./bonus/parse_bonus.c\
					./bonus/check_argument_bonus.c\
					./bonus/check_closed_map_bonus.c\
					./bonus/map_parse_bonus.c\
					./bonus/map_parse_utils_bonus.c\
					./bonus/type_parse_bonus.c\
					./bonus/type_parse_utils_bonus.c\
					./bonus/draw_map_bonus.c\
					./bonus/draw_one_line_bonus.c\
					./bonus/draw_in_image_bonus.c\
					./bonus/print_image_bonus.c\
					./bonus/cal_perp_dist_bonus.c\
					./bonus/dda_bonus.c\
					./bonus/valid_map_bonus.c\
					./bonus/key_handler_bonus.c\
					./bonus/input_wasd_bonus.c\
					./bonus/input_right_left_bonus.c\
					./bonus/put_error_bonus.c\
					./bonus/init_img_bonus.c\
					./bonus/init_handle_img_bonus.c\
					./bonus/destroy_handler_bonus.c\
					./bonus/mouse_handler_bonus.c\
					./bonus/draw_mini_map_bonus.c\
					./bonus/door_bonus.c\
					./bonus/door_update_bonus.c\
					./bonus/init_racing_mode_bonus.c\
					./bonus/init_notice_img_bonus.c\
					./bonus/init_current_img_bonus.c\

OBJS			=	$(SRCS:%.c=%.o)

OBJS_B			=	$(SRCS_B:%.c=%.o)

RM			=	rm -f

all			:	$(NAME)

bonus		:	$(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

$(NAME)	: $(OBJS) 
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDES) $(LIBS) $^ -o $@

$(NAME_B)	: $(OBJS_B)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDES_B) $(LIBS) $^ -o $@

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re
