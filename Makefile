NAME = ft_ssl

SRC_DIR = src/
OBJ_DIR = obj/
SUB_DIR = io/ MD5/ SHA256/ util/

SRC_RAW =   main \
            get_file_contents \
            load_ftssl_opts \
            handle_stdin \
            print_explicit_format \
            md5 \
            process_md5 \
            process_sha256 \
            sha256 \
            quartet_to_hex \
            swap_endian_uint64 \
            del_msg \
            init_msg \
            ft_ssl_usage

SRC = $(SRC_RAW:%=$(SRC_DIR)%.c)
OBJ = $(SRC_RAW:%=$(OBJ_DIR)%.o)

LIB =   libft/libft.a
INC =   -I includes/ -I libft/includes

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

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(LOGO) Compiling:$(CY) $@ $(CE)$(CR)"
	@gcc -c $< -o $@ $(INC)

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: 
	gcc $(LIBFT_INC) -g libft/src/*.c libft/src/ft_printf/src/* $(INC) $(SRC) -o $(NAME)
