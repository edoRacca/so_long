/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:04 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/18 12:07:28 by edraccan         ###   ########.fr       */
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
	else if (key == XK_Up || key == XK_w || key == XK_q)
		move_up(data);
	else if (key == XK_Down || key == XK_s || key == XK_z)
		move_down(data);
	else if (key == XK_Left || key == XK_a || key == XK_s)
		move_left(data);
	else if (key == XK_Right || key == XK_d || key == XK_d)
		move_right(data);
	print_map(data);
	// printf("%d\n", key);
	return (0);
}

