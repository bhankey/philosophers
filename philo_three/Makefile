SRCS	=	main.c print.c ft_atoi.c validate_init.c philo_process.c ft_itoa.c exit_func.c \
			utils.c monitor.c

NAME	=	philo_three

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror  -I.

LIB		=	-pthread

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re