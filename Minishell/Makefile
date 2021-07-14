NAME	=	minishell

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

LFLAGS	=	-I. -lncurses -lreadline

LIBFT	=	./libft/libft.a 

SRCS	=	./srcs/main/main.c \
			./srcs/gc/garbage_co.c \
			./srcs/cmd/handle_cmd.c \
			./srcs/cmd/cmd_tools.c \
			./srcs/lists/lists.c \
			./srcs/error/error.c\
			./srcs/env/env.c
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
