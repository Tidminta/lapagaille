NAME	=	pipex

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g

LFLAGS	=	-I. -lncurses -lreadline #-fsanitize=address

LIBFT	=	./libft/libft.a

SRCS	=	./main.c \
			./exec.c \
			./init.c \
			./parse.c \
			./utils.c 

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
			./pipex

.PHONY:		all clean fclean re f
