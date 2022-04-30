NAME		=	libft.a

CC			=	gcc

SRCS		=	ft_atoi.c ft_itoa.c \
					ft_putchar.c ft_putnbr.c \
					ft_putstr.c ft_strlen.c \
 
OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar crs ${NAME} ${OBJS}

bonus:		${OBJS_BONUS}
			ar cr ${NAME} ${OBJS_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
