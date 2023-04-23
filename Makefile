NAME		=	./cub3D

LIBFTDIR	= ./libft

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
#-g3 -fsanitize=address
MLX_FLAGS	=	-framework OpenGL -framework Appkit

INCLUDES 	=	-I ./libft/ \
				-I ./mlx/\
   				-I .

LIBS		=	-L ./libft/ -l ft\
				-L ./mlx/ -l mlx

SRCS			=	./main.c\
					./init.c\
					./split_is_function.c\
					./map_list_util.c\
					./parse.c\
					./check_argument.c\
					./check_closed_map.c\
					./map_parse.c\
					./type_parse.c\
					./draw_map.c\
					./draw_one_line.c\
					./draw_in_image.c\
					./print_image.c\
					./cal_perp_dist.c\
					./dda.c\
					./valid_map.c\
					./key_handler.c\


OBJS			=	$(SRCS:%.c=%.o)

RM			=	rm -f

all			:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

$(NAME)	: $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDES) $(LIBS) $^ -o $@

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re