/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:13:24 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/12 04:37:47 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
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

}			t_data;

/*
enum		e_pos
{
	collect_x,
	collect_y,
	exit_x,
	exit_y,
	player_x,
	player_y
};

int			pos[6];

pos[collect_x];
 */

//  gnl et utils

char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

//  split

char		**ft_split(char const *s, char c);

//  check features
int			check_item(char **map);
int			check_spawn(char **map);
int			check_exit(char **map);
int			check_others(char **map);

//  check parsing

char		*chr_map(char *str);
int			checkfile(char *file);
char		**full_map(char *str);
int			check_up_border(char **map);
int			check_down_border(char **map);
int			check_side_border(char **map);
int			check_len_line(char **map);
int			all_check(char **map);

//  grab position

void		grab_exit_pos(t_data *data);
void		grab_player_pos(t_data *data);

//  path finding

void	    all_path(t_data *data, int i, int j);
void		path_finding(t_data *data);

#endif
