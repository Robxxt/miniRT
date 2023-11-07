# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 07:54:51 by rdragan           #+#    #+#              #
#    Updated: 2023/11/07 09:36:09 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
SRC		=	src/main.c \
			src/is_valid_file_extension.c \
			src/is_valid_file.c \
			src/ft_atof.c \
			src/is_valid_float_number.c \
			src/get_file_content.c \
			src/print_lst.c \
			src/validate_file_content.c \
			src/check_element_utils.c \
			src/validate_element_a.c \
			tests/parsing_tests.c \
			tests/test_is_valid_file_extension.c \
			tests/test_is_valid_file.c \
			tests/test_ft_atof.c \
			tests/test_is_valid_float_number.c \
			tests/test_validate_element_a.c \
			tests/test_check_element_utils.c
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra -g
LIBFT_PATH	=	libs/libft
LIBFT_ARCHIVE_PATH	=	$(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_ARCHIVE_PATH) 
	@ echo "Compiling ..."
	@ $(CC) $(LIBFT_ARCHIVE_PATH) $^ -o $(NAME)

$(LIBFT_ARCHIVE_PATH): $(LIBFT_PATH)
	make -C $(LIBFT_PATH)

$(BUILD_LIBFT):


clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all