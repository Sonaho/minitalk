SRCS_CLIENT	= client.c
SRCS_C_BONUS = client_bonus.c
SRCS_SERVER	= server.c
SRCS_S_BONUS = server_bonus.c

NAME_CLIENT	= client
NAME_SERVER	= server
NAME		= libft.a

OBJS_CLIENT	= ${SRCS_CLIENT:.c=.o}
OBJS_C_BONUS = ${SRCS_C_BONUS:.c=.o}
OBJS_SERVER	= ${SRCS_SERVER:.c=.o}
OBJS_S_BONUS = ${SRCS_S_BONUS:.c=.o}


CFLAGS		= -Wall -Werror -Wextra
CC			= gcc


all:	${NAME}

client:	${OBJS_CLIENT}
		${MAKE} all -C ./libft
		cp -p libft/${NAME} ./${NAME}
		${CC} ${CFLAGS} ${OBJS_CLIENT} ${NAME} -o ${NAME_CLIENT}

server:	${OBJS_SERVER}
		${MAKE} all -C ./libft
		cp -p libft/${NAME} ./${NAME}
		${CC} ${CFLAGS} ${OBJS_SERVER} ${NAME} -o ${NAME_SERVER}

${NAME}:	client server

bonus_client: ${OBJS_C_BONUS}
			${MAKE} all -C ./libft
			cp -p libft/${NAME} ./${NAME}
			${CC} ${CFLAGS} ${OBJS_C_BONUS} ${NAME} -o ${NAME_CLIENT}

bonus_server: ${OBJS_S_BONUS}
			${MAKE} all -C ./libft
			cp -p libft/${NAME} ./${NAME}
			${CC} ${CFLAGS} ${OBJS_S_BONUS} ${NAME} -o ${NAME_SERVER}

bonus: bonus_client bonus_server

clean:
		${MAKE} clean -C ./libft
		rm -f ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_C_BONUS} ${OBJS_S_BONUS}

fclean:	clean
		rm -f ${NAME} ${NAME_CLIENT} ${NAME_SERVER} 

re:		fclean ${NAME}