# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 18:59:28 by sharris           #+#    #+#              #
#    Updated: 2018/11/12 01:08:23 by sharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR = includes/
SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = ft_abs.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isempty.c \
			ft_islower.c \
			ft_isprint.c \
			ft_isupper.c \
			ft_iswhitespace.c \
			ft_itoa.c \
			ft_itoabase.c \
			ft_lltoa.c \
			ft_lstadd.c \
			ft_lstcount.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstdelone_f.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpush.c \
			ft_max.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_merge_sort.c \
			ft_mod.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putwstr.c \
			ft_putstr_fd.c \
			ft_realloc.c \
			ft_stpncpy.c \
			ft_strcat.c \
			ft_strcfjoin.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strffjoin.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstolsts.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wordcount.c \
			ft_wstrcpy.c \
			ft_wstrdup.c \
			ft_wstrffjoin.c \
			ft_wstrjoin.c \
			ft_wstrlen.c \
			ft_wstrnew.c \
			ft_wstrsub.c \
			get_next_line.c \
			merge_strcmp_f.c

OBJ = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
HEADER = $(INC_DIR)/libft.h

FT_PF_DIR = $(SRC_DIR)ft_printf/
FT_PRINTF = libftprintf.a

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

all: mkdir $(NAME) $(FT_PRINTF)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $<

mkdir: $(OBJ_DIR)
	
$(OBJ_DIR):
	mkdir obj

$(FT_PRINTF):
	make -C $(FT_PF_DIR)

clean:
	rm -Rf $(OBJ_DIR)
	rm -Rf $(FT_PF_DIR)obj/

fclean: clean
	rm -f $(NAME)
	rm -f $(FT_PRINTF)

re: fclean all 

.PHONY: clear, fclean, all, re, mkdir
