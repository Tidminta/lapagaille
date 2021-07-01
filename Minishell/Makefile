NAME	=	minishell

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-g

LFLAGS	=	-I. -lncurses

LIBFT	=	./lib/libft/libft.a

SRCS	=	./srcs/main/main.c
			./srcs/cmd/handle_cmd.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C lib/libft
			${CC} ${CFLAGS} ${LFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean:
			$(RM) $(OBJS)
			make clean -C lib/libft

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean $(NAME)

f:			re
			./minishell

.PHONY:		all clean fclean re f