# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 07:54:51 by rdragan           #+#    #+#              #
#    Updated: 2023/12/20 12:05:19 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
SRC		=	src/main.c \
			debugging.c \
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
			src/check_is_valid_list.c \
			src/validate_sp.c \
			src/validate_pl.c \
			src/validate_cy.c \
			src/validate_cb.c \
			src/parser.c \
			src/populate_context_elements.c \
			src/read_list.c \
			src/populate_objects.c \
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
			src/mlx/paint_img.c \
			src/api/rgb_to_color.c \
			src/api/ambient_to_ambt.c \
			src/api/float_to_vector.c \
			src/api/camara_to_cmr.c \
			src/api/light_to_lit.c \
			src/api/sphere_to_sp.c \
			src/api/plane_to_panel.c \
			src/api/cylinder_to_cylind.c \
			src/api/image_to_space.c \
			src/is_valid_texture.c \
			src/api/validate_image_vectors.c\
			src/main_utils.c \
			src/init_obj_and_amount.c


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