/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 01:51:25 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/15 05:38:37 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dclose(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data);
	free(data->mlx);
	exit(1);
}

void	setupimg(t_data *data)
{
	int w;
	int	h;
	
	data->joueur = mlx_xpm_file_to_image(data->mlx, "images/joueur.xpm", &w, &h);
	if (data->joueur == NULL)
		return;
	data->mur = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &w, &h);
	if (data->mur == NULL)
		return;
	data->sol = mlx_xpm_file_to_image(data->mlx, "images/sol.xpm", &w, &h);
	if (data->sol == NULL)
		return;
	data->exit = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", &w, &h);
	if (data->exit == NULL)
		return;
}

int	key_hook(int keycode, t_data *data)
{
	
	if (keycode == 65307)
		dclose(data); 
	if (keycode ==  13)
		move_up(data);
	if (keycode == 0)
		move_down(data);
	if (keycode == 2)
		move_right(data);
	if (keycode == 1)
		move_left(data);
	return (0);
}