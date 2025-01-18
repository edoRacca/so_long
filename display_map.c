/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:38:08 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/18 16:31:36 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_imgs(t_struct *data)
{
	data->width = WIMG;
	data->height = HIMG;
	data->p_img = mlx_xpm_file_to_image(data->mlx, data->p_path, &data->width, &data->height);
	data->e_img = mlx_xpm_file_to_image(data->mlx, data->e_path, &data->width, &data->height);
	data->c_img = mlx_xpm_file_to_image(data->mlx, data->c_path, &data->width, &data->height);
	data->w_img = mlx_xpm_file_to_image(data->mlx, data->w_path, &data->width, &data->height);
}

void	fullfill_map(t_struct *data)
{
	int i;

	i = 0;
	while (data->map[i])
	{
		int j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1')
				mlx_put_image_to_window(data->mlx, data->win, data->w_img, j * WIMG, i * HIMG);
			j++;
		}
		i++;
	}
}

void	map_start(t_struct *data)
{
	create_imgs(data);
	fullfill_map(data);
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

void	print_map(t_struct *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("%d %s\n", i, data->map[i]);
		i++;
	}
}