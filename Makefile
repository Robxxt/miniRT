# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 07:54:51 by rdragan           #+#    #+#              #
#    Updated: 2023/12/13 09:01:34 by tiqin            ###   ########.fr        #
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
			src/validate_element_l.c \
			src/validate_element_c.c \
			src/validate_rgb.c \
			src/split_len.c \
			src/is_valid_list.c \
			src/validate_sp.c \
			src/validate_pl.c \
			src/validate_cy.c \
			src/validate_cb.c \
			src/parser.c \
			src/populate_context_elements.c \
			src/read_list.c \
			src/populate_objects.c \
			tests/parsing_tests.c \
			tests/test_is_valid_file_extension.c \
			tests/test_is_valid_file.c \
			tests/test_ft_atof.c \
			tests/test_is_valid_float_number.c \
			tests/test_validate_element_a.c \
			tests/test_validate_element_l.c \
			tests/test_validate_element_c.c \
			tests/test_check_element_utils.c \
			tests/test_validate_rgb.c \
			tests/test_split_len.c \
			tests/test_validate_sp.c \
			tests/test_validate_pl.c \
			tests/test_validate_cy.c \
			src/camera/rays.c \
			src/color/color.c \
			src/function/quadratic.c \
			src/geomerty/lines.c \
			src/geomerty/vector.c \
			src/tracing/cube.c \
			src/tracing/cylinder.c \
			src/tracing/panel.c \
			src/tracing/sphere.c \
			src/tracing/tracing.c \
			src/mlx/paint_img.c

OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra -g
LIBFT_PATH	=	libs/libft
LIBFT_ARCHIVE_PATH	=	$(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_ARCHIVE_PATH) 
	@ echo "Compiling ..."
	make -C mlx/
	$(CC) $(LIBFT_ARCHIVE_PATH) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_ARCHIVE_PATH): $(LIBFT_PATH)
	make -C $(LIBFT_PATH)

$(BUILD_LIBFT):

# test: $(LIBFT_ARCHIVE_PATH)
# 	make -C mlx/
# 	$(CC) $(CFLAGS) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all