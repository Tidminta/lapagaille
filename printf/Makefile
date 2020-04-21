# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 00:09:25 by tidminta          #+#    #+#              #
#    Updated: 2020/04/21 14:43:20 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB_DIR = libft/
LIB = libft.a

FLAGS	=	-Wall -Wextra -Werror

# [ src ]

SRC =	./ft_init_structs.c\
		./ft_putchar_fd2.c\
		./ft_putstr_fd2.c\
		./ft_putnbr_fd2.c\
		./ft_putnbr_base.c\
		./ft_isprint.c\
		./ft_isdigit.c\
		./ft_format.c\
		./ft_format2.c\
		./ft_printf.c\
		./ft_printing.c\
		./ft_print_unsigned.c\
		./ft_unsigned_0flag.c\
		./ft_unsigned_flag0.c\
		./ft_unsigned_flagm.c\
		./ft_print_hexa.c\
		./ft_hexa_flag0.c\
		./ft_hexa_0flag.c\
		./ft_hexa_flagminus.c\
		./ft_print_digits.c\
		./ft_d_0flag.c\
		./ft_d_flag0.c\
		./ft_d_flagminus.c\
		./ft_print_char.c\
		./ft_print_string.c\
		./ft_string_0flag.c\
		./ft_string_flagm.c\
		./ft_print_addr.c\
		./ft_addr_0flag.c\
		./ft_addr_flagminus.c\
		./ft_print_pourcent.c\
		./ft_print_bin_bonus.c\
		./ft_bin_0flag.c\
		./ft_bin_flag0.c\
		./ft_bin_flagm.c

# [ obj]

OBJ_DIR = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $?
	@ranlib $@
	@echo "Indexing ... OK"

$(OBJ): |$(OBJ_DIR)

$(OBJ_DIR):
	@make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIB) $(NAME)
	@echo "Creating [$(LIB)] ... OK"
	@mkdir $@
	@echo "Creating [$@] directory ... OK"

$(OBJ_DIR)%.o: %.c
	gcc $(FLAG) -I . -I $(LIB_DIR) -c $? -o $@
	@echo "Compiling [$?] ... OK"

bonus: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)*.o
	@echo "Cleaning ... OK"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)$(LIB)

re:	fclean all

.PHONY:	all bonus clean fclean re