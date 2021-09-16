# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 18:01:31 by tidminta          #+#    #+#              #
#    Updated: 2021/09/15 02:11:21 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g

LFLAGS	=	-I. #-fsanitize=address

LIBFT	=	./libft/libft.a

SRCS	=	./srcs/main.c \
			./srcs/init.c \
			./srcs/tools.c 

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			${CC} ${CFLAGS} ${LFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean:
		$(RM) $(OBJS)
		make clean -C libft

fclean:	clean
		$(RM) $(NAME) $(LIBFT)

re:                     fclean $(NAME)

f:	re
	./philo

.PHONY:	all clean fclean re f