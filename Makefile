FILES = srcs/main.c \
	
OBJETS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -llibft/libft.a

CC = cc

NAME = push_swap

all: $(NAME)

make_lib:
	make -C libft

$(NAME): make_lib $(OBJETS)
	$(CC) $(CFLAGS) $(OBJETS) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJETS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
