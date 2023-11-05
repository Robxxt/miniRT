# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 07:54:51 by rdragan           #+#    #+#              #
#    Updated: 2023/11/05 08:25:20 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
SRC		=	src/main.c \
			src/is_valid_file_extension.c \
			src/is_valid_file.c \
			tests/test_is_valid_file_extension.c \
			tests/test_is_valid_file.c \
			tests/parsing_tests.c
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra
LIBFT_PATH	=	libs/libft
LIBFT_ARCHIVE_PATH	=	$(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "Compiling ..."
	@ if [ ! -f $(LIBFT_ARCHIVE_PATH) ]; then make -C $(LIBFT_PATH); fi
	@ cc $(LIBFT_ARCHIVE_PATH) $^ -o $(NAME)


clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all