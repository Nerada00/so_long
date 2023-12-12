/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/12 02:32:02 by abdmessa         ###   ########.fr       */
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
	static t_data data = {0};

	if (ac == 2)
	{
		int i = 0;

		data.file = av[1];
		if (checkfile(data.file) == 1)
			printf("%s\n", "bonne extention de fichier\n");
		else if (checkfile(data.file) == 0)
			return(printf("%s\n", "L'extention du fichier n'est pas bonne"), 1);
		data.map = full_map(data.file);
		data.tab = full_map(data.file);
		printf("\n=================\n");
		printf ("       map");
		printf("\n=================\n\n");

		if (all_check(data.map) == 1)
		{
			while (data.map[i])
			{
				printf("{%i} %s\n", i, data.map[i]);
				i++;
			}
		}
		/////////////////////		/////////////////////

		i = 0;
		printf("\n=================\n");
		printf ("       tab");
		printf("\n=================\n\n");
		grab_exit_pos(&data);
		grab_player_pos(&data);
		if (all_check(data.map) == 1)
		{
			path_finding(&data);
			while (data.tab[i])
			{
				printf("{%i} %s\n", i, data.tab[i]);
				i++;
			}
		}
		/////////////////////		/////////////////////

		printf("\nexit_position_x -> %d\n", data.exit_x);
		printf("exit_position_y -> %d\n\n", data.exit_y);
		
		printf("player_position_x -> %d\n", data.player_x);
		printf("player_position_y -> %d\n", data.player_y);
	}
	return (0);
}
