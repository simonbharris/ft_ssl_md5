NAME = ft_ssl_md5

SRC_DIR = src/
SRC_RAW = main
SRC = $(SRC_RAW:%=$(SRC_DIR)%.c)

LIBFT_INC = -I libft/includes/ -I libft/src/ft_printf/includes

all:
	gcc -Llibft/ -lft -lftprintf -I libft/includes/ $(SRC) -o $(NAME)

debug: 
	gcc $(LIBFT_INC) -g libft/src/*.c libft/src/ft_printf/src/* $(SRC) -o $(NAME)
