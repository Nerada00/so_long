/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 05:35:34 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/16 07:20:47 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	free_doubletab(char **str)
{
	const char	**ptr = (const char **)str;

	while (*str)
	{
		free(*str);
		str++;
	}
	free(ptr);
}
