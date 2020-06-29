# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 18:20:36 by tidminta          #+#    #+#              #
#    Updated: 2020/06/26 19:45:06 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs/

SRC_GNL_PATH = ./srcs_gnl/

SRC_CUB_PATH = ./srcs_cub/

INCLUDE_PATH = ./includes/

OBJ_PATH = ./objs/

MLX_NAME = ./mlx/libmlx.a

MAIN = main.c

SRC_NAME =		ft_memset.c\
            	ft_bzero.c\
                ft_memcpy.c\
                ft_memccpy.c\
                ft_memchr.c\
                ft_memcmp.c\
                ft_memmove.c\
                ft_strlen.c\
                ft_isalpha.c\
                ft_isdigit.c\
                ft_isalnum.c\
                ft_strnstr.c\
                ft_strncmp.c\
                ft_strlcpy.c\
                ft_strlcat.c\
                ft_atoi.c\
                ft_strdup.c\
                ft_calloc.c\
                ft_substr.c\
                ft_strjoin.c\
                ft_strtrim.c\
                ft_split.c\
                ft_itoa.c\
                ft_putchar_fd.c\
                ft_putstr_fd.c\
                ft_putendl_fd.c\
                ft_putnbr_fd.c\
                ft_strchr.c\
                ft_strrchr.c\
                ft_isascii.c\
                ft_isprint.c\
                ft_strmapi.c\
                ft_toupper.c\
                ft_tolower.c \
				ft_lstsize.c\
                ft_lstnew.c\
                ft_lstmap.c\
                ft_lstlast.c\
                ft_lstiter.c\
                ft_lstdelone.c\
                ft_lstclear.c\
                ft_lstadd_front.c\
                ft_lstadd_back.c \

SRC_GNL_NAME = 	get_next_line.c\
				get_next_line_utils.c\

SRC_CUB_NAME =	ft_parsemap.c\
				ft_parsemap2.c\
				ft_tools.c\

INCLUDE_SRC_NAME = libft.h

INCLUDE_GNL_NAME = get_next_line.h

INCLUDE_CUB_NAME = cub3d.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_GNL_NAME = $(SRC_GNL_NAME:.c=.o)

OBJ_PRINTF_NAME = $(SRC_CUB_NAME:.c=.o)


SRC = $(addprefix $(SRC_PATH), $(SRC_NAME) \
				$(SRC_GNL_NAME)) \
				$(SRC_CUB_NAME)) \
				

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME) $(OBJ_GNL_NAME) $(OBJ_PRINTF_NAME))

HEADER_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME))

HEADER_GNL_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_GNL_NAME))

HEADER_CUB_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME) $(INCLUDE_CUB_NAME))

INCLUDE = -I$(INCLUDE_PATH)

FLAGS = -Wall

.PHONY: all, clean, fclean, re, f

all: $(NAME)
	@gcc $(FLAGS) -lmlx -lXext -lX11 -lbsd -o Cub3D $(MAIN) $(NAME) mlx/libmlx.a

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_GNL_PATH)%.c $(HEADER_GNL_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_CUB_PATH)%.c $(HEADER_CUB_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -Imlx_linux -O3 -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

f: re
	./Cub3D maps/test.cub