SRC		= ft_printchar.c \
		ft_printstr.c \
		ft_printpointer.c \
		ft_printdigit.c \
		ft_printu.c \
		ft_printhexadec.c \
		ft_printpercent.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \
		ft_printf.c
OBJ		= ${SRC:.c=.o}
NAME		= libftprintf.a
HEADER		= ft_printf.h
CC			= cc 
CFLAGS 		= -Wall -Wextra -Werror
%.o: %.c libft.h
			${CC}${CFLAGS} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJ} ${HEADER}
			ar rcs ${NAME} ${OBJ}

clean:
			rm -f ${OBJ}
fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


