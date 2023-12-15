/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/15 05:44:36 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}
int	error(t_data *data, char *str)
{
	ft_printf("Erreur de map: %s\n", str);
	free_tab(data->tab);
	free_tab(data->map);
	exit(1);
}

int	ft_strlen_double(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])	
		i++;
	return (i);
}


int	main(int ac, char **av)
{
	static t_data	data = {0};

	

	if (ac != 2)
		return (ft_printf("Veuillez entrer un argument\n"));
	data.file = av[1];
	path_finding(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 50 * ft_strlen(data.map[0]), 50 * ft_strlen_double(data.map), "So_long");

	setupimg(&data);
	for (int i = 0; data.map[i]; i++)
		for (int j = 0; data.map[i][j]; j++)
		{
			if (data.map[i][j] == '1')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.mur, j * 50, i * 50);
			if (data.map[i][j] == '0')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.sol, j * 50, i * 50);
			if (data.map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.joueur, j * 50, i * 50);
			if (data.map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.exit, j * 50, i * 50);
	
		}
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	key_hook(data.keycode, &data);
	mlx_loop(data.mlx);
	return (0);
}
