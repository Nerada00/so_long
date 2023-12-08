/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:35 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/08 20:32:34 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*chr_map(char *file)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*str;

    str = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (NULL);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		str = ft_strjoin(str, tmp);
		tmp = get_next_line(fd);
	}
	return (str);
}

char	**full_map(char *file)
{
	int		i;
	char	**map;
	char	*str;

	i = 0;
	str = chr_map(file);
	map = ft_split(str, '\n');
	return (map);
}
