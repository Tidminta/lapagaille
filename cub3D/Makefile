# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 18:20:36 by tidminta          #+#    #+#              #
#    Updated: 2020/07/13 19:28:26 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub.a

SRC_PATH = ./srcs/

SRC_GNL_PATH = ./srcs_gnl/

SRC_PRINTF_PATH = ./srcs_printf/

SRC_CUB_PATH = ./srcs_cub/

MLX_PATH = ./mlx/

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDE_PATH = ./includes/

OBJ_PATH = ./objs/

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
				ft_parsemap.c\
				ft_parsemap2.c\
				ft_check_map.c\
				ft_tools.c\
				ft_start_mlx.c\
				ft_raycast.c\
				ft_check_map.c\
				ft_raycast.c\
				ft_raycast2.c\

SRC_GNL_NAME = 	get_next_line.c\
				get_next_line_utils.c\

SRC_PRINTF_NAME = ft_init_structs.c\
                ft_putchar_fd2.c\
                ft_putstr_fd2.c\
                ft_putnbr_fd2.c\
                ft_putnbr_base.c\
                ft_isprint.c\
                ft_isdigit.c\
                ft_format.c\
                ft_format2.c\
                ft_printf.c\
                ft_printing.c\
                ft_print_unsigned.c\
                ft_unsigned_0flag.c\
                ft_unsigned_flag0.c\
                ft_unsigned_flagm.c\
                ft_print_hexa.c\
                ft_hexa_flag0.c\
                ft_hexa_0flag.c\
                ft_hexa_flagminus.c\
                ft_print_digits.c\
                ft_d_0flag.c\
                ft_d_flag0.c\
                ft_d_flagminus.c\
                ft_print_char.c\
                ft_print_string.c\
                ft_string_0flag.c\
                ft_string_flagm.c\
                ft_print_addr.c\
                ft_addr_0flag.c\
                ft_addr_flagminus.c\
                ft_print_pourcent.c\
                ft_print_bin_bonus.c\
                ft_bin_0flag.c\
                ft_bin_flag0.c\
                ft_bin_flagm.c\
                ft_lstsize.c\
                ft_lstnew.c\
                ft_lstmap.c\
                ft_lstlast.c\
                ft_lstiter.c\
                ft_lstdelone.c\
                ft_lstclear.c\
                ft_lstadd_front.c\
                ft_lstadd_back.c\

INCLUDE_SRC_NAME = libft.h

INCLUDE_GNL_NAME = get_next_line.h

INCLUDE_PRINTF_NAME = libftprintf.h

INCLUDE_CUB_NAME = 	cub3d.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_GNL_NAME = $(SRC_GNL_NAME:.c=.o)

OBJ_PRINTF_NAME = $(SRC_PRINTF_NAME:.c=.o)

OBJ_CUB_NAME = $(SRC_CUB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME) \
				$(SRC_GNL_NAME) \
				$(SRC_PRINTF_NAME) \
				$(SRC_CUB_NAME))
				
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME) $(OBJ_GNL_NAME) $(OBJ_PRINTF_NAME) $(OBJ_CUB_NAME))

HEADER_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME))

HEADER_GNL_SRC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_GNL_NAME))

HEADER_SRC_PRINTF = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME) $(INCLUDE_PRINTF_NAME))

HEADER_SRC_CUB = $(addprefix $(INCLUDE_PATH), $(INCLUDE_SRC_NAME) $(INCLUDE_PRINTF_NAME) $(INCLUDE_CUB_NAME))

INCLUDE = -I$(INCLUDE_PATH)

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re, f

all: $(NAME)
	@gcc $(FLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework Appkit -o Cub3D $(MAIN) $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_GNL_PATH)%.c $(HEADER_GNL_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PRINTF_PATH)%.c $(HEADER_SRC_PRINTF)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<
	
$(OBJ_PATH)%.o: $(SRC_CUB_PATH)%.c $(HEADER_SRC_CUB)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

f: re
	./Cub3D maps/test2.cub