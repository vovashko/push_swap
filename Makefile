NAME	= push_swap

SRCS	= push_swap.c utils.c error_handling.c sorting/algorithm.c \
			sorting/cheapest_search.c sorting/node_finder.c  sorting/pushers.c \
			commands/swap.c commands/push.c commands/rotate.c commands/rev_rotate.c 

OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFT = libft/libft.a

$(NAME):	$(OBJS)
			make -C libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			$(RM) $(OBJS)

fclean:		clean 
			make fclean -C libft
			$(RM) $(NAME) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re