FILES = main.c \
		utilities.c \

SRC =	$(wildcard ./src/parse/*.c) \
		$(wildcard ./src/render/*.c) \
		src/main.c \
		src/utilities.c

OS_NAME := $(shell uname -s | tr A-Z a-z)

LIBFT = libft

NAME = miniRT

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft

# MLX = libmlx

# MLX_FLAGS = -L. -lmlx -lX11 -lXext -lm

ifeq ($(OS_NAME),linux)
	MLX = libmlx
	MLX_FLAGS = -L. -lmlx -lX11 -lXext -lm
else
	MLX = libmlx_opengl
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME}

${NAME}: ${LIBFT}.a ${MLX}.a ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT}.a ${MLX}.a ${MLX_FLAGS} -o ${NAME}

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
