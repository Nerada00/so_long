/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/11 07:14:05 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkfile(char *file)
{
	int	i;

	i = 0;
	i = ft_strlen(file);
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i
		- 3] == 'b' && file[i - 4] == '.')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_data data;
	t_pos pos;
	t_pos pos2;

	pos = (t_pos){0};
	if (ac == 2)
	{
		int i = 0;
		data.file = av[1];
		if (checkfile(data.file) == 1)
			printf("%s\n", "bonne extention de fichier\n");
		else if (checkfile(data.file) == 0)
			return(printf("%s\n", "L'extention du fichier n'est pas bonne"), 1);
		char **map = full_map(data.file);
		while (map[i] && all_check(map) == 1)
		{
			printf("{%i} %s\n", i, map[i]);
			i++;
		}
		pos = grab_exit_pos(map);
		pos2 = grab_player_pos(map);
		if (pos.exit_x == -1 || pos.exit_y == -1)
			return (printf("no valid coordinate for exit\n"), 1);
		printf("\nposition %d\n", pos.exit_x);
		printf("position %d\n\n", pos.exit_y);
		
		printf("position %d\n", pos2.player_x);
		printf("position %d\n", pos2.player_y);
	}
	return (0);
}
