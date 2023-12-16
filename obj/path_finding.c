/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:52:58 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 08:00:46 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	secure(t_data *data)
{
	char	*str;

	str = chr_map(data->file);
	if (checkfile(data->file) == 0)
		return (free(str), ft_printf("%s\n",
				"Error\nL'extention du fichier n'est pas bonne"), 0);
	if (!str)
		return (ft_printf("Error\nLa map n'existe pas"), 0);
	free((void *)str);
	data->map = full_map(data->file);
	if (!data->map)
		return (ft_printf("Error\nMap introuvable\n"), 0);
	data->tab = full_map(data->file);
	return (all_check(data));
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
					return (0);
				j++;
			}
			j = 0;
			i++;
		}
		return (ft_printf("Map Complete OK\n\n"), 1);
	}
	else
		return (ft_printf("Error\nMap impossible\n"), 0);
}

int	path_finding(t_data *data)
{
	if (secure(data) == 0)
	{
		if (data->tab)
			free_doubletab(data->tab);
		if (data->map)
			free_doubletab(data->map);
		return (0);
	}
	grab_exit_pos(data);
	grab_player_pos(data);
	if (!path_collect(data))
	{
		if (data->tab)
			free_doubletab(data->tab);
		if (data->map)
			free_doubletab(data->map);
		return (0);
	}
	return (1);
}
