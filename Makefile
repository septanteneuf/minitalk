# NAME1	=	server
# NAME2	=	client
# NAME3	=	utils

# CC		=	gcc

# #SRCS 	= 	src/ \

# OBJS	=	${SRCS:.c=.o}

# RM		=	rm -rf

# FLAGS	=	-Wall -Wextra -Werror 

# all:
# 			$(CC) $(CFLAGS) server.c -o $(NAME1)
# 			$(CC) $(CFLAGS) client.c -o $(NAME2)
# 			$(CC) $(CFLAGS) utils.c -o $(NAME3)

# ${NAME}:	${OBJS}
# 			cc ${FLAGS} ${OBJS} -o ${NAME}

# %.o : %.c
# 			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

# clean:
# 			${RM} ${OBJS}

# fclean:		clean
# 			${RM} ${NAME1} ${NAME2} $(NAME3)

# re:			fclean all

# .PHONY: 	all clean fclean re

CLIENT_NAME			=	client
CLIENT_BONUS		=	bonus/client

CLIENT_SRCS			=	client.c
CLIENT_OBJS			=	$(CLIENT_SRCS:.c=.o)

CLIENT_SRCS_BONUS	=	client_bonus.c
CLIENT_OBJS_BONUS	=	$(CLIENT_SRCS_BONUS:.c=.o)

SERVER_NAME			=	server

SERVER_BONUS		=	bonus/server

SERVER_SRCS			=	server.c
SERVER_OBJS			=	$(SERVER_SRCS:.c=.o)

SERVER_SRCS_BONUS	=	server_bonus.c
SERVER_OBJS_BONUS	=	$(SERVER_SRCS_BONUS:.c=.o)

INC					=	minitalk.h

LIBFT				=	libft/libft.a

CFLAGS				=	-Wall -Wextra -Werror -I $(INC)

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $< -o $@

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(LIBFT) $(CLIENT_OBJS)
			gcc $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(LIBFT) $(SERVER_OBJS)
			gcc $(SERVER_OBJS) $(LIBFT) -o $(SERVER_NAME)

bonus:	bonus_create $(CLIENT_BONUS) $(SERVER_BONUS)

bonus_create :
	mkdir -p bonus

$(CLIENT_BONUS): $(LIBFT) $(CLIENT_OBJS_BONUS)
			gcc $(CLIENT_OBJS_BONUS) $(LIBFT) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(LIBFT) $(SERVER_OBJS_BONUS)
			gcc $(SERVER_OBJS_BONUS) $(LIBFT) -o $(SERVER_BONUS)

$(LIBFT) :
			$(MAKE) -C libft

clean:
			rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
			$(MAKE)	-C libft clean

fclean:		clean
			rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS) $(SERVER_BONUS)
			$(MAKE)	-C libft fclean

re:			fclean all

.PHONY:		all clean fclean re bonus bonus_create
