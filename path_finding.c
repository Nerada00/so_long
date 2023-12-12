/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:52:58 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/12 04:49:51 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_tab(char **tab){

    printf("\n");
    for(int i=0; tab[i]; i++){
        printf("%s\n", tab[i]);
    }
}

void	path_finding(t_data *data)
{
	int	i;
	int	j;
    all_path(data, data->player_y, data->player_x);
    while (1)
    {

        data->read = 0;
        i = 0;
        j = 0;
	    while (data->tab[i])
	    {
            
		    while (data->tab[i][j])
	    	{   
		    	if (data->tab[i][j] == 'X')
			    	all_path(data, i, j);
			    j++;
		    }
		    j = 0;
		    i++;
	    }   
        if (data->tab[data->exit_y][data->exit_x] != 'E' || data->read == 0)
            break;
        usleep(1000000);
        display_tab(data->tab);
    }    
}
