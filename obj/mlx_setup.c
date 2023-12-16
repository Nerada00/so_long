/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 01:51:25 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 08:09:14 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dclose(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->mur)
		mlx_destroy_image(data->mlx, data->mur);
	if (data->joueur)
		mlx_destroy_image(data->mlx, data->joueur);
	if (data->sol)
		mlx_destroy_image(data->mlx, data->sol);
	if (data->collect)
		mlx_destroy_image(data->mlx, data->collect);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free_doubletab(data->map);
	free_doubletab(data->tab);
	free(data->mlx);
	exit(1);
}

void	setupimg(t_data *data)
{
	data->joueur = mlx_xpm_file_to_image(data->mlx, "images/joueur.xpm",
			&data->w, &data->h);
	data->mur = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &data->w,
			&data->h);
	data->sol = mlx_xpm_file_to_image(data->mlx, "images/sol.xpm", &data->w,
			&data->h);
	data->exit = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", &data->w,
			&data->h);
	data->collect = mlx_xpm_file_to_image(data->mlx, "images/collect.xpm",
			&data->w, &data->h);
	if (!data->joueur || !data->mur || !data->sol || !data->exit)
		dclose(data);
}

void	display(t_data *data)
{
	const void	*images[256] = {['0'] = data->sol, ['P'] = data->joueur,
	['E'] = data->exit, ['1'] = data->mur, ['C'] = data->collect};
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++i, data->map[i])
	{
		while (++j, data->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				(void *)images[(unsigned)data->map[i][j]], j * PIXEL_SIZE, i
				* PIXEL_SIZE);
			last(data);
		}
		j = -1;
	}
}

void	print_image(t_data *data)
{
	display(data);
	if (data->map[data->player_y][data->player_x] ==
	data->map[data->exit_y][data->exit_x]
		&& count_c(data) == 0)
		dclose(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		dclose(data);
	if (keycode == UP)
		move_up(data);
	if (keycode == DOWN)
		move_down(data);
	if (keycode == RIGHT)
		move_right(data);
	if (keycode == LEFT)
		move_left(data);
	return (0);
}
