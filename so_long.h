/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:13:24 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/08 20:33:38 by abdmessa         ###   ########.fr       */
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

typedef struct t_data {
    char **map;
    char *file;
}   t_data;

char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);


char	**ft_split(char const *s, char c);

char    *chr_map(char *str);
char    **full_map(char *str);
#endif
