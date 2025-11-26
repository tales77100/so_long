FILES = srcs/main.c \
	
OBJETS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/libft.h -g3 

CC = cc

NAME = so_long

LIB_PATH = libft/libft.a

all: $(NAME)

make_lib:
	make -C libft

$(NAME): make_lib $(OBJETS)
	$(CC) $(CFLAGS) -lmlx -lXext -lX11  $(OBJETS) $(LIB_PATH) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJETS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
