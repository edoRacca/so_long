/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:04 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/20 19:16:58 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_player(t_struct *data)
{
	data->width = WIMG;
	data->height = HIMG;
	mlx_destroy_image(data->mlx, data->p_img);
	data->p_img = mlx_xpm_file_to_image(data->mlx, data->p_path, \
					&data->width, &data->height);
}

int	ft_render(int key, t_struct *data)
{
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx, data->p_img);
		mlx_destroy_image(data->mlx, data->e_img);
		mlx_destroy_image(data->mlx, data->c_img);
		mlx_destroy_image(data->mlx, data->g_img);
		mlx_destroy_image(data->mlx, data->w_img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_maps(data);
		exit (0);
	}
	else if (key == XK_Up || key == XK_w || key == XK_q)
		move_up(data, key);
	else if (key == XK_Down || key == XK_s || key == XK_z)
		move_down(data, key);
	else if (key == XK_Left || key == XK_a || key == XK_s)
		move_left(data, key);
	else if (key == XK_Right || key == XK_d || key == XK_d)
		move_right(data, key);
	return (0);
}
