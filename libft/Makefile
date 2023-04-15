CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	= 	libft.a
INC		=	libft.h
SRC		=	./ft_atoi.c			\
			./ft_bzero.c		\
			./ft_calloc.c		\
			./ft_isalnum.c		\
			./ft_isalpha.c		\
			./ft_isascii.c		\
			./ft_isdigit.c		\
			./ft_isprint.c		\
			./ft_memchr.c		\
			./ft_memcmp.c		\
			./ft_memcpy.c		\
			./ft_memmove.c		\
			./ft_memset.c		\
			./ft_strchr.c		\
			./ft_strdup.c		\
			./ft_strlcat.c		\
			./ft_strlcpy.c		\
			./ft_strlen.c		\
			./ft_strncmp.c		\
			./ft_strnstr.c		\
			./ft_strrchr.c		\
			./ft_tolower.c		\
			./ft_toupper.c		\
			./ft_substr.c		\
			./ft_strjoin.c		\
			./ft_strtrim.c		\
			./ft_split.c		\
			./ft_itoa.c			\
			./ft_strmapi.c		\
			./ft_striteri.c		\
			./ft_putchar_fd.c	\
			./ft_putendl_fd.c	\
			./ft_putnbr_fd.c	\
			./ft_putstr_fd.c	\
			./ft_isspace.c		\
			./ft_lstdel.c		\
			./get_next_line.c	\

OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f
AR		=	ar rc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@$(AR) $@ $(OBJ)

$(OBJ)	:	$(SRC)
	@$(CC) $(CFLAGS) -c $^ -I $(INC)

clean	:
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
