/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:21:31 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/11 07:05:58 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos grab_exit_pos(char **map)
{
    t_pos pos;
    int	i;
	int	j;
    
	i = 0;
	j = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'E')
            {
                pos.exit_x = j;
                pos.exit_y = i;
            }
            j++;
        }
        i++;
    } 
    return (pos);
}

t_pos grab_player_pos(char **map)
{
    t_pos pos;
    int	i;
	int	j;
    
	i = 0;
	j = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'P')
            {
                pos.player_x = j;
                pos.player_y = i;
            }
            j++;
        }
        i++;
    } 
    return (pos);
}
