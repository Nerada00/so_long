/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:30:28 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/13 06:19:20 by abdmessa         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	static t_data	data = {0};

	if (ac != 2)
		return (ft_printf("Veuillez entrer un argument\n"));
	data.file = av[1];
	path_finding(&data);
	return (0);
}
