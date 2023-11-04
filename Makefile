# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 07:54:51 by rdragan           #+#    #+#              #
#    Updated: 2023/11/04 08:48:36 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
SRC		=	src/test.c
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra
LIBFT_PATH	=	lib/libft
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