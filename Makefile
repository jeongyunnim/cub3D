NAME		=	./cub3D

LIBFTDIR	= ./libft

CC			=	cc
CFLAGS		=	\
#-Wall -Wextra -Werror \

INCLUDES 	=	-I ./libft/ \
   				-I .

LIBS		=	-L ./libft/ -lft

SRCS			=	./main.c\
					./split_is_function.c\
					./map_list_util.c\
					./parse.c\
					./check_argument.c\
					./map_parse.c\
					./type_parse.c\

OBJS			=	$(SRCS:%.c=%.o)

AR			=	ar rcs
RM			=	rm -f

all			:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

$(NAME)	: $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $^ -o $@

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re