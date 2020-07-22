# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 18:20:36 by tidminta          #+#    #+#              #
#    Updated: 2020/07/22 02:50:15 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

SRC_PATH = ./srcs/

SRC_GNL_PATH = ./srcs_gnl/

MLX_PATH = ./mlx/

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDE_PATH = ./includes/

OBJ_PATH = ./objs/

MAIN = main.c

SRC_NAME =		ft_parsemap.c\
				ft_parsemap2.c\
				ft_check_map.c\
				ft_tools.c\
				ft_raycast.c\
				ft_check_map.c\
				ft_raycast.c\
				ft_move.c\

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

.PHONY: all, clean, fclean, re, f, f2

all: $(NAME)
	@$(MAKE) -C libft
	@gcc $(FLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework Appkit $(MAIN) $(NAME) ./libft/libft.a -o Cub3D 

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
	@/bin/rm -f $(NAME)

re: fclean all

f: re
	./Cub3D maps/test.cub

f2: re
	./Cub3D maps/test2.cub