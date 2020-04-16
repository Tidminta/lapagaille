# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 00:09:25 by tidminta          #+#    #+#              #
#    Updated: 2020/04/16 17:47:28 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC  = gcc

RM	= rm -f

OBJ =	./libft/ft_bzero.c\
		./libft/ft_strlen.c\
		./libft/ft_atoi.c\
		./libft/ft_strdup.c\
		./libft/ft_calloc.c\
		./libft/ft_substr.c\
		./libft/ft_init_structs.c\
		./libft/ft_putchar_fd.c\
		./libft/ft_putstr_fd.c\
		./libft/ft_putnbr_fd.c\
		./libft/ft_putnbr_base.c\
		./libft/ft_isprint.c\
		./libft/ft_isdigit.c\
		./libft/ft_format.c\
		./libft/ft_format2.c\
		./libft/ft_printf.c\
		./libft/ft_printing.c\
		./libft/ft_print_unsigned.c\
		./libft/ft_unsigned_0flag.c\
		./libft/ft_unsigned_flag0.c\
		./libft/ft_unsigned_flagm.c\
		./libft/ft_print_hexa.c\
		./libft/ft_hexa_flag0.c\
		./libft/ft_hexa_0flag.c\
		./libft/ft_hexa_flagmoins.c\
		./libft/ft_print_digits.c\
		./libft/ft_d_0flag.c\
		./libft/ft_d_flag0.c\
		./libft/ft_d_flagmoins.c\
		./libft/ft_print_char.c\
		./libft/ft_print_string.c\
		./libft/ft_string_0flag.c\
		./libft/ft_string_flagm.c\
		./libft/ft_print_addr.c\
		./libft/ft_addr_0flag.c\
		./libft/ft_addr_flagmoins.c\
		./libft/ft_print_pourcent.c\
		./libft/ft_print_bin_bonus.c\
		./libft/ft_bin_0flag.c\
		./libft/ft_bin_flag0.c\
		./libft/ft_bin_flagm.c

OBJ_OBJS	=	$(OBJ:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

LIB			= ./libft/libftprintf.h

%.o : %.c
	@$(CC) $(CFLAGS) -I. -o $@ -c $<


$(NAME): $(OBJ_OBJS) $(LIB) Makefile
			ar rc $(NAME) $(OBJ_OBJS)
			ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean all re