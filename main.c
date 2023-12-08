/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/08 20:41:12 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkfile(char *file)
{
	while (av[1][i])
	{
		i++;
	}
	i -= 4
	
}

int	main(int ac, char **av)
{
	t_data data;
	if (ac == 2)
	{
		int i = 0;
		data.file = av[1];
		if (checkfile(data.file))
			return (1);
 		// parse le nom du fichier
		char **map = full_map(data.file);
		while (map[i])
		{
			printf("{%i}%s\n", i, map[i]);
			i++;
		}
		
	}
}