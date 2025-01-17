/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:04 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/17 19:22:37 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Questa funzione fa in modo che premendo il tasto esc la finestra
// si chiuda
int	ft_render(int key, t_struct *data)
{
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx, data->p_img);
		mlx_destroy_image(data->mlx, data->e_img);
		mlx_destroy_image(data->mlx, data->c_img);
		mlx_destroy_image(data->mlx, data->w_img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_maps(data);
		exit (0);
	}
	else if (key == 65362 || key == 119 || key == 113)
	{
		data->p_pos[1]--;
		map_start(data);
	}
	printf("%d\n", key);
	return (0);
}

