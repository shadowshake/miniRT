SRC = fractol.c	img_helper.c frac_helper.c	drawfrac.c

LIBFT = libft

MLX = libmlx

NAME = fractol

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -L. -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	${CC} -Imlx -c $< -o $@

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

