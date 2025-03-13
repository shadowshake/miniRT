NAME = libft.a

SRC_DIR = ft_printf

FILES = ft_printchar.c \
		ft_printf.c \
		ft_printint.c \
		ft_printlowhex.c \
		ft_printstr.c \
		ft_printunsignedint.c \
		ft_printuphex.c \
		ft_printhex.c

SRC = $(addprefix $(SRC_DIR)/, $(FILES))

OBJS = $(SRC:%.c=%.o)

LIBFTNAME = libft.a

LIBFTPATH = ./libft

FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	cp $(LIBFTPATH)/$(LIBFTNAME) $(NAME)
	ar rc $(NAME) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME) $(LIBFTNAME)
	make fclean -C $(LIBFTPATH)

re: fclean all