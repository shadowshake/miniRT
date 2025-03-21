FILES = main.c \
		utilities.c \

SRC =	$(wildcard ./src/parse/*.c) \
		$(wildcard ./src/render/*.c) \
		src/main.c \
		src/utilities.c

LIBFT = libft

MLX = libmlx

NAME = miniRT

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft

%.o: %.c
	${CC} ${CFLAGS} -Imlx_linux -c $< -o $@

all: ${NAME}

${NAME}: ${LIBFT}.a ${MLX}.a ${OBJS}
	${CC} ${CFLAGS} -L. -lmlx -lX11 -lXext -lm ${OBJS} ${LIBFT}.a ${MLX}.a -o ${NAME}

${LIBFT}.a: 
	${MAKE} re -C ${LIBFT}
	mv ${LIBFT}/${LIBFT}.a ./

${MLX}.a:
	${MAKE} re -C ${MLX}
	mv ${MLX}/${MLX}.a ./

clean:
	rm -f ${OBJS}
	rm -f ${LIBFT}.a
	rm -f ${MLX}.a
	${MAKE} fclean -C ${LIBFT}
	${MAKE} clean -C ${MLX}

fclean: clean
	rm -f ${NAME}

re: fclean all

