SRC = so_long.c\

OBJS = ${SRCS:.c =.o}

NAME = so_long

CC = cc

CFLAGS = 		-Wall -Werror -Wextra -g -L/mlx 

L_FLAGS =		-lmlx -lXext -lX11

RM =			rm -f

all	:	${NAME}

%.o: %.c
	$(CC) $(CFLAGS) $(L_FLAGS) -c $< -o $@
$(NAME) :       $(OBJS)
	$(CC) $(OBJ) -Lmlx-macos- -lmlx-macos -framework OpenGL -framework AppKit -o $(NAME)

clean	:	$(RM) $(OBJS)

fclean	:	clean

			${RM} ${NAME}

re	:	fclean all

.PHONY	:	clean fclean all re
