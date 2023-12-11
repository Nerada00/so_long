/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 03:19:12 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/11 06:11:55 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_others(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
int	check_item(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (printf("plusieurs sortis"), 0);
}
int	check_spawn(char **map)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (printf("plusieurs spawn"), 0);
}