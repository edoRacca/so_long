/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:38:08 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/16 15:25:13 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_imgs(t_struct *data)
{
	data->p_wimg = WIMG;
	data->p_himg = HIMG;
	data->e_wimg = WIMG;
	data->e_himg = HIMG;
	data->c_wimg = WIMG;
	data->c_himg = HIMG;
	data->p_img = mlx_xpm_file_to_image(data->mlx, data->p_path, &data->p_wimg, &data->p_himg);
	data->e_img = mlx_xpm_file_to_image(data->mlx, data->e_path, &data->e_wimg, &data->e_himg);
	data->c_img = mlx_xpm_file_to_image(data->mlx, data->c_path, &data->c_wimg, &data->c_himg);
}

void	map_start(t_struct *data)
{
	create_imgs(data);
	// fullfill_map();
	mlx_put_image_to_window(data->mlx, data->win, data->p_img, data->p_pos[0] * HIMG, data->p_pos[1] * WIMG);
	mlx_put_image_to_window(data->mlx, data->win, data->e_img, data->e_pos[0] * HIMG, data->e_pos[1] * WIMG);
	int i = 0;
	while (data->map[i])
	{
		int j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->c_img, j * HIMG, i * WIMG);
			j++;
		}
		i++;
	}
}
