/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 08:02:17 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(t_data *data, char *str)
{
	ft_printf("Error\nErreur de map: %s\n", str);
	free_doubletab(data->tab);
	free_doubletab(data->map);
	return (1);
}

int	ft_strlen_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	static t_data	data = {0};

	if (ac != 2)
		return (ft_printf("Error\nVeuillez entrer un argument\n"));
	data.file = av[1];
	if (path_finding(&data) == 1)
	{
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
		data.mlx_win = mlx_new_window(data.mlx, PIXEL_SIZE
				* ft_strlen(data.map[0]), PIXEL_SIZE
				* ft_strlen_double(data.map), "So_long");
		setupimg(&data);
		print_image(&data);
		mlx_key_hook(data.mlx_win, &key_hook, &data);
		mlx_hook(data.mlx_win, 17, 0, dclose, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
