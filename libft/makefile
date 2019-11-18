# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 00:09:25 by tidminta          #+#    #+#              #
#    Updated: 2019/11/18 20:02:13 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c

OBJ		=	$(subst .c,.o,$(SRC))
CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		gcc $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re