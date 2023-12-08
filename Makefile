#fonction

SRCS		= 	so_long.c \
				pars_border.c \
				main.c \
				init_map.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_split.c \


OBJS		= $(SRCS:.c=.o)

#commande

NAME		=		so_long
CC			=		cc
CFLAGS		= 		-Wall -Werror -Wextra -g 
#L_FLAGS 	=		-lmlx -lXext -lX11
RM			=		rm -f

all	: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME)	: $(OBJS)
		$(CC) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean fclean all re
