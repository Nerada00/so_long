/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:35 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/13 06:36:17 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkfile(char *file)
{
	int	i;

	i = 0;
	i = ft_strlen(file);
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b' && file[i
		- 4] == '.')
		return (ft_printf("\n[bonne extention]\n"), 1);
	else
		return (ft_printf("\n[mauvaise extention]\n"), 0);
}
char	*chr_map(char *file)
{

	int		fd;
	char	*tmp;
	char	*str;
	bool	stop;

	str = NULL;
	stop = false;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s", "Erreur lors de l'ouverture\n"), NULL);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (tmp[0] == '\n')
			stop = true;
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	if (stop)
		return (free(str), NULL);
	return (str);
}

char	**full_map(char *file)
{
	char	**map;
	char	*str;

	str = chr_map(file);
	if (!str)
		return (NULL);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
