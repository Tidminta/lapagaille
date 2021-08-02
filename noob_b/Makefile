NAME	=	minishell

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g3

LFLAGS	=	-I. -lncurses -lreadline

LIBFT	=	./libft/libft.a

SRCS	=	./srcs/main/main.c \
			./srcs/gc/garbage_co.c \
			./srcs/cmd/handle_cmd.c \
			./parsing/parsing_pass1/parsing_p.c \
			./parsing/parsing_pass1/parsing_p_par.c	\
			./parsing/parsing_pass1/parsing_p_quotes.c \
			./parsing/parsing_pass1/parsing_p_quotes_2.c \
			./parsing/parsing_pass1/parsing_p_symbol.c \
			./parsing/parsing_pass2/parsing_p_p_par.c \
			./parsing/string_utils.c \
			./parsing/string_utils_2.c \
			./parsing/string_utils_3.c \
			./init/init1.c \
			./parsing/parsing_pass2/parsing_p_p_token.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			${CC} ${CFLAGS} ${LFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean:
			$(RM) $(OBJS)
			make clean -C libft

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean $(NAME)

f:			re
			./minishell

.PHONY:		all clean fclean re f
