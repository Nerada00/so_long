/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:13:24 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 07:54:57 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define PIXEL_SIZE 32

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;
	char	**tab;
	char	*file;
	int		collect_x;
	int		collect_y;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	int		read;
	void	*collect;
	void	*mlx;
	void	*joueur;
	void	*mur;
	void	*sol;
	void	*exit;
	void	*mlx_win;
	int		keycode;
	int		w;
	int		h;
	int		count;
	int		mouv;
}			t_data;

// ft_printf

int			ft_printf(const char *s, ...);
int			ft_putnbr(int nb);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_count(int nb);
int			ft_print_digit(unsigned long int nb, char *base);
int			ft_print_format(char spec, va_list ap);
size_t		ft_strlen2(char *str);

//  gnl et utils

char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

//  split

char		**ft_split(char const *s, char c);

//  check features
int			check_item(t_data *data);
int			check_spawn(t_data *data);
int			check_exit(t_data *data);
int			check_others(t_data *data);

//  check parsing

char		*chr_map(char *str);
int			checkfile(char *file);
char		**full_map(char *str);
int			check_up_border(t_data *data);
int			check_down_border(t_data *data);
int			check_side_border(t_data *data);
int			check_len_line(t_data *data);
int			all_check(t_data *data);

void		check_to_print(t_data *data);

//  grab position

void		grab_exit_pos(t_data *data);
void		grab_player_pos(t_data *data);

//  path finding

void		all_path(t_data *data, int i, int j);
int			path_exit(t_data *data);
int			path_collect(t_data *data);

//	gestion d'erreur

int			error(t_data *data, char *str);
int			path_finding(t_data *data);

//	move

void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

// close & setup

int			dclose(t_data *data);
void		setupimg(t_data *data);
int			key_hook(int keycode, t_data *data);
void		print_image(t_data *data);
int			count_c(t_data *data);
void		last(t_data *data);

//	free

void		ft_memdel(void **ptr);
void		free_doubletab(char **str);
#endif
