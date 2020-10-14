# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 18:20:36 by tidminta          #+#    #+#              #
#    Updated: 2020/10/14 17:20:35 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

SRC_PATH = ./srcs/

SRC_GNL_PATH = ./srcs_gnl/

MLX_PATH = ./mlx/

MLX = -Imlx -Lmlx -lmlx -framework OpenGL -framework Appkit

INCLUDE_PATH = ./includes/

OBJ_PATH = ./objs/

ASAN = -fsanitize=address -g -O3

SRC_NAME =		main.c\
				init.c\
				parsemap.c\
				parsemap2.c\
				check_map.c\
				tools.c\
				check_map.c\
				raycast.c\
				move.c\
				keys.c\
				textures.c\
				sprite.c\
				sprite2.c\
				free.c

SRC_GNL_NAME = 	get_next_line.c\
				get_next_line_utils.c\

INCLUDE_GNL_NAME = get_next_line.h

INCLUDE_SRC_NAME = 	cub.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_GNL_NAME = $(SRC_GNL_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME) \
				$(SRC_GNL_NAME))
				
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME) $(OBJ_GNL_NAME))

HEADER_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME))

HEADER_GNL_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_GNL_NAME))

INCLUDE = -I$(INCLUDE_PATH)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	@$(MAKE) -C libft
	@gcc -g $(ASAN) $(FLAGS) $(MLX) $(NAME) ./libft/libft.a -o Cub3D 

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_GNL_PATH)%.c $(HEADER_GNL_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@$(MAKE) clean -C ./libft
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@$(MAKE) fclean -C ./libft
	@/bin/rm -f $(NAME) Cub3D

re: fclean all

f: re
	./Cub3D maps/test.cub

f2: re
	./Cub3D maps/test2.cub

.PHONY: all, clean, fclean, re, f, f2