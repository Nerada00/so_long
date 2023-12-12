/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:19:57 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/12 04:37:23 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_up(t_data *data, int i, int j)
{
	while (data->tab[i][j] != '1')
	{
		if (data->tab[i][j] != 'X')
		{
			data->read = 1;
			data->tab[i][j] = 'X';
		}
		i--;
	}
}
void	path_down(t_data *data, int i, int j)
{
	while (data->tab[i][j] != '1')
	{
		if (data->tab[i][j] != 'X')
		{
			data->read = 1;
			data->tab[i][j] = 'X';
		}
		i++;
	}
}
void	path_right(t_data *data, int i, int j)
{
	while (data->tab[i][j] != '1')
	{
		if (data->tab[i][j] != 'X')
		{
			data->read = 1;
			data->tab[i][j] = 'X';
		}
		j++;
	}
}
void	path_left(t_data *data, int i, int j)
{
	while (data->tab[i][j] != '1')
	{
		if (data->tab[i][j] != 'X')
		{
			data->read = 1;
			data->tab[i][j] = 'X';
		}
		j--;
	}
}

void	all_path(t_data *data, int i, int j)
{
	path_up(data, i, j);
	path_down(data, i, j);
	path_right(data, i, j);
	path_left(data, i, j);
}