FILES = main.c \
		#read.c \

SRC =	$(wildcard ./src/parse/*.c) \
		src/$(FILES)	

LIBFT = libft

MLX = libmlx

NAME = miniRT

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft -L. -lmlx -lX11 -lXext -lm

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME}

${NAME}: ${LIBFT}.a ${MLX}.a ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT}.a ${MLX}.a -o ${NAME}

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

