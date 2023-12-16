/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 03:19:12 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 07:59:23 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_others(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'C' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'E' && data->map[i][j] != '0'
				&& data->map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_item(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_exit(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (ft_printf("Error\nplusieurs sortis\n"), 0);
}

int	check_spawn(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	else if (count > 1)
		return (ft_printf("Error\nPlusieurs spawn"), 0);
	else
		return (ft_printf("Error\nAucun spawn\n"), 0);
}

int	count_c(t_data *data)
{
	int	i;
	int	j;
	int	cmp;

	cmp = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				cmp++;
			j++;
		}
		j = 0;
		i++;
	}
	return (cmp);
}
