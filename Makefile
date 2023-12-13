#fonction

SRCS		= 	obj/so_long.c \
				obj/pars_border.c \
				obj/main.c \
				obj/init_map.c \
				obj/get_next_line/get_next_line.c \
				obj/get_next_line/get_next_line_utils.c \
				obj/ft_split.c \
				obj/features.c \
				obj/positions.c \
				obj/path_check.c \
				obj/path_finding.c \
				obj/printf/ft_printf.c \
				obj/printf/ft_printf_fonction.c \


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
