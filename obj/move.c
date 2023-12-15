/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 01:30:59 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/15 03:38:06 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void    move_up(t_data *data)
{
    if (data->map[data->player_y -1][data->player_x] == '1')
        return ;
    else  
    {
        data->player_y -= 1;
        data->map[data->player_y +1][data->player_x] = '0';
        data->map[data->player_y][data->player_x] = 'P';
        return ;
    }
}

void    move_down(t_data *data)
{
    if (data->map[data->player_y +1][data->player_x] == '1')
        return ;
    else  
    {
        data->player_y += 1;
        data->map[data->player_y -1][data->player_x] = '0';
        data->map[data->player_y][data->player_x] = 'P';
        return ;
    }
}
void    move_left(t_data *data)
{
    if (data->map[data->player_y][data->player_x -1] == '1')
        return ;
    else  
    {
        data->player_x -= 1;
        data->map[data->player_y][data->player_x+1] = '0';
        data->map[data->player_y][data->player_x] = 'P';
        return ;
    }
}
void    move_right(t_data *data)
{
    if (data->map[data->player_y][data->player_x +1] == '1')
        return ;
    else  
    {
        data->player_x += 1;
        data->map[data->player_y][data->player_x-1] = '0';
        data->map[data->player_y][data->player_x] = 'P';
        return ;
    }
}
