FILES = srcs/main.c \
	
OBJETS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/libft.h -g3 -MMD -MP

CC = cc

NAME = so_long

LIB_PATH = libft/libft.a
LIBX_PATH = mlx/libmlx_Linux.a
FT_PRINTF_PATH = libft/ft_printf/libftprintf.a

all: $(NAME)

make_lib:
	make -C libft

make_libx:
	make -C mlx

$(NAME): make_lib make_libx $(OBJETS)
	$(CC) $(CFLAGS) -I mlx -lXext -lX11 -lm -lz $(OBJETS) $(LIB_PATH) $(LIBX_PATH) $(FT_PRINTF_PATH) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJETS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
