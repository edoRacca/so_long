/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:38:08 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/15 18:13:33 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_start(t_struct *data)
{
	data->p_img_w = 32;
	data->p_img_h = 32;
	data->p_img = mlx_xpm_file_to_image(data->mlx, data->p_path, &data->p_img_w, &data->p_img_h);
	mlx_put_image_to_window(data->mlx, data->win, data->p_img, data->p_pos[0] * HEIGHT, data->p_pos[1] * WIDTH);
	// int i = 0;
	// while (data->map[i])
	// {
	// 	int j = 0;
	// 	while (data->map[i][j])
	// 	{
	// 		if (data->map[i][j] == 'P')
	// 			mlx_put_image_to_window(data->mlx, data->win, data->img, j, i);
	// 		j++;
	// 	}
	// 	i++;
	// }
}