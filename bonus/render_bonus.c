/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:04 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/21 17:03:46 by edraccan         ###   ########.fr       */
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
		ft_cross_close(data);
	else if (key == XK_Up || key == XK_w)
		move_up(data, key);
	else if (key == XK_Down || key == XK_s)
		move_down(data, key);
	else if (key == XK_Left || key == XK_a)
		move_left(data, key);
	else if (key == XK_Right || key == XK_d)
		move_right(data, key);
	return (0);
}
