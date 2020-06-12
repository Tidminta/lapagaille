# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 18:43:54 by tidminta          #+#    #+#              #
#    Updated: 2020/06/11 19:12:44 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test.a

SRC_PATH = ./srcs/

MLX_PATH = ./mlx/

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDE_PATH = ./includes/

OBJ_PATH = ./objs/

MAIN = main.c

SRC_NAME	= lib.c \

INCLUDE_SRC_NAME = lib.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME))

INCLUDE = -I$(INCLUDE_PATH)

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re, f

all: $(NAME)
	gcc $(FLAGS) $(MAIN) $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_SRC)
	mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all