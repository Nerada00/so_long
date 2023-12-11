/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:13:24 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/11 07:06:41 by abdmessa         ###   ########.fr       */
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

typedef struct t_data
{
	char	**map;
	char	*file;
}			t_data;

/*
enum e_pos 
{
    collect_x,
    collect_y,
    exit_x,
    exit_y,
    player_x,
    player_y
};

int pos[6];

pos[collect_x];
 */
 
typedef struct  t_pos
{
    int collect_x;
    int collect_y;
    int exit_x;
    int exit_y;
    int player_x;
    int player_y;
}           t_pos;

//  gnl et utils
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

//  split
char		**ft_split(char const *s, char c);

//  check features
int         check_item(char **map);
int         check_spawn(char **map);
int         check_exit(char **map);
int         check_others(char **map);


//  check parsing
char		*chr_map(char *str);
char		**full_map(char *str);
int			check_up_border(char **map);
int         check_down_border(char **map);
int         check_side_border(char **map);
int         check_len_line(char **map);
int         all_check(char **map);

//  grab position

t_pos       grab_exit_pos(char **map);
t_pos       grab_player_pos(char **map);


#endif
