/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:52:58 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/13 06:21:56 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	display_tab(char **tab)
// {
// 	ft_printf("\n");
// 	for (int i = 0; tab[i]; i++)
// 	{
// 		ft_printf("%s\n", tab[i]);
// 	}
// }
int	secure(t_data *data)
{
	if (checkfile(data->file) == 0)
		return (ft_printf("%s\n", "L'extention du fichier n'est pas bonne"), 0);
	if (chr_map(data->file) == NULL)
		return (ft_printf("La map n'existe pas"), 0);
	data->map = full_map(data->file);
	if (!data->map)
		return (ft_printf("Map introuvable\n"), 0);
	data->tab = full_map(data->file);
	if (all_check(data) == 0)
		return (error(data, "Map invalide check\n"), 0);
	return (1);
}

int	path_exit(t_data *data)
{
	int	i;
	int	j;

	while (1)
	{
		data->read = 0;
		i = 0;
		while (data->tab[i])
		{
			j = 0;
			while (data->tab[i][j])
			{
				if (data->tab[i][j] == 'X')
					all_path(data, i, j);
				j++;
			}
			i++;
		}
		if (data->tab[data->exit_y][data->exit_x] != 'E' && data->read == 0)
			return (ft_printf("======== Sortie Trouvable ========\n\n"), 1);
		// display_tab(data->tab);         test a chaque passage
		else if (data->read == 0)
			return (0);
	}
}


int	path_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	all_path(data, data->player_y, data->player_x);
	if (path_exit(data) == 1)
	{
		while (data->tab[i])
		{
			while (data->tab[i][j])
			{
				if (data->tab[i][j] == 'C')
					return (ft_printf(" Sortie OK ====== Collectible KO\n\n"), 0);
				j++;
			}
			j = 0;
			i++;
		}
		return (ft_printf("Map Complete OK\n\n"), 1);
	}
	else
		return (ft_printf(" Map impossible\n"), 0);
}


int	path_finding(t_data *data)
{
	if (secure(data) == 0)
		return (0);
	int i = 0;
	ft_printf("\n==============================================================\n");
	ft_printf("|      			     map			     |");
	ft_printf("\n==============================================================\n\n");
	grab_exit_pos(data);
	grab_player_pos(data);
	if (path_collect(data) == 1 && all_check(data) == 1)
	{
		while (data->map[i])
		{
			ft_printf("%s  %s\n", "||", data->map[i]);
			i++;
		}
		return (1);
	}
	else
		return (0);
}