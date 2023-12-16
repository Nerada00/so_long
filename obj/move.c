/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 01:30:59 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 08:02:39 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == '1')
		return ;
	else
	{
		if (data->map[data->player_y - 1][data->player_x] == 'C')
			++data->count;
		data->player_y -= 1;
		data->map[data->player_y + 1][data->player_x] = '0';
		data->map[data->player_y][data->player_x] = 'P';
		data->mouv++;
		print_image(data);
		ft_printf("position :[%d;%d] mouv {%d}\n", data->player_x,
			data->player_y, data->mouv);
		return ;
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == '1')
		return ;
	else
	{
		if (data->map[data->player_y + 1][data->player_x] == 'C')
			++data->count;
		data->player_y += 1;
		data->map[data->player_y - 1][data->player_x] = '0';
		data->map[data->player_y][data->player_x] = 'P';
		data->mouv++;
		print_image(data);
		ft_printf("position :[%d;%d] mouv {%d}\n", data->player_x,
			data->player_y, data->mouv);
		return ;
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == '1')
		return ;
	else
	{
		if (data->map[data->player_y][data->player_x - 1] == 'C')
			++data->count;
		data->player_x -= 1;
		data->map[data->player_y][data->player_x + 1] = '0';
		data->map[data->player_y][data->player_x] = 'P';
		data->mouv++;
		print_image(data);
		ft_printf("position :[%d;%d] mouv {%d}\n", data->player_x,
			data->player_y, data->mouv);
		return ;
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == '1')
		return ;
	else
	{
		if (data->map[data->player_y][data->player_x + 1] == 'C')
			++data->count;
		data->player_x += 1;
		data->map[data->player_y][data->player_x - 1] = '0';
		data->map[data->player_y][data->player_x] = 'P';
		data->mouv++;
		print_image(data);
		ft_printf("position :[%d;%d] mouv {%d}\n", data->player_x,
			data->player_y, data->mouv);
		return ;
	}
}

void	last(t_data *data)
{
	if (data->map[data->player_y][data->player_x] ==
	data->map[data->exit_y][data->exit_x])
		data->map[data->exit_y][data->exit_x] = 'P';
	else
		data->map[data->exit_y][data->exit_x] = 'E';
}
