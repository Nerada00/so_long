SRCS = obj/pars_border.c \
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
       obj/move.c \
       obj/mlx_setup.c \
       obj/free.c \

MLX = libmlx_Linux.a

OBJS = $(SRCS:.c=.o)

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
L_FLAGS = -lm -lXext -lX11 -Lmlx -lXfixes -lmlx -L/usr/lib
RM = rm -f

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C mlx
	@cp mlx/$(MLX) .
	$(CC) $(OBJS) $(MLX) $(L_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(MLX)

re: fclean all

.PHONY: clean fclean all re
