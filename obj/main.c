/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/14 04:59:51 by abdmessa         ###   ########.fr       */
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

	void	*mlx;
	void	*mlx_win;

	if (ac != 2)
		return (ft_printf("Veuillez entrer un argument\n"));
	data.file = av[1];
	path_finding(&data);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 50 * ft_strlen(data.map[0]), 50 * ft_strlen_double(data.map), "So_long");
	int w, h;
	void *joueur = mlx_xpm_file_to_image(mlx, "images/joueur.xpm", &w, &h);
	void *mur = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &w, &h);
	void *sol = mlx_xpm_file_to_image(mlx, "images/sol.xpm", &w, &h);
	void *exit = mlx_xpm_file_to_image(mlx, "images/exit.xpm", &w, &h);
	for (int i = 0; data.map[i]; i++)
		for (int j = 0; data.map[i][j]; j++)
		{
			if (data.map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, mur, j * 50, i * 50);
			if (data.map[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, sol, j * 50, i * 50);
			if (data.map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, joueur, j * 50, i * 50);
			if (data.map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, exit, j * 50, i * 50);
			//mlx_key_hook()
		}
	mlx_loop(mlx);
	return (0);
}
