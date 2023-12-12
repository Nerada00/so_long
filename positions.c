/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:21:31 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/12 01:09:45 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    grab_exit_pos(t_data *data)
{
    int	i;
	int	j;
    
	i = 0;
	j = 0;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'E')
            {
                data->exit_x = j;
                data->exit_y = i;
            }
            j++;
        }
        i++;
    } 
}

void    grab_player_pos(t_data *data)
{
    int	i;
	int	j;
    
	i = 0;
	j = 0;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->player_x = j;
                data->player_y = i;
            }
            j++;
        }
        i++;
    } 
}
