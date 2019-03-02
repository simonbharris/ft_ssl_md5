NAME = ft_ssl

SRC_DIR = src/
OBJ_DIR = obj/

SRC_RAW =   main \
            get_file_contents \
            load_ftssl_opts \
            handle_stdin \
            print_explicit_format \
            md5 \
            process_md5 \
            process_sha256 \
			process_sha512 \
			sha224 \
            sha256 \
			sha384 \
			sha512 \
            quartet_to_hex \
            swap_endian_uint64 \
            del_msg \
            init_msg \
            ft_ssl_usage


SRC = $(SRC_RAW:%=%.c)
OBJ = $(SRC_RAW:%=$(OBJ_DIR)%.o)

LIB =   libft/libft.a libft/libftprintf.a
INC = includes/ft_ssl.h

INC_FLAGS =   -I includes/ -I libft/includes
W_FLAGS = -Wall -Wextra -Werror

VPATH = src/io/ src/md5/ src/sha/ src/util/ src/msg_t src/


CK = \033[K
CG = \033[92m
CY = \033[93m
CE = \033[0m
CR = \033[1A
LOGO = $(CK)$(CG)[$(NAME)]

$(NAME): $(OBJ_DIR) $(OBJ) $(LIB)
	@gcc -Llibft/ -lft -lftprintf -I libft/includes/ $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(LOGO) Built:$(CY) ft_ssl$(CE)"

all: $(NAME)

$(LIB):
	@make -C libft/

$(OBJ_DIR):
	@echo "$(LOGO) Making$(CY) ft_ssl$(CE)"
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)%.o: %.c
	@echo "$(LOGO) Compiling:$(CY) $@ $(CE)$(CR)"
	@gcc $(W_FLAGS) -c $< -o $@ $(INC_FLAGS)

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: 
	gcc $(LIBFT_INC) -g libft/src/*.c libft/src/ft_printf/src/* $(INC) $(SRC) -o $(NAME)
