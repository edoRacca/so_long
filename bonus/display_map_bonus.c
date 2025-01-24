/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:38:08 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/24 12:14:49 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_imgs(t_struct *data)
{
	int	w_stepsbg;
	int	h_stepsbg;

	data->width = WIMG;
	data->height = HIMG;
	w_stepsbg = 90;
	h_stepsbg = 20;
	data->w_img = mlx_xpm_file_to_image(data->mlx, data->w_path, \
					&data->width, &data->height);
	data->p_img = mlx_xpm_file_to_image(data->mlx, data->p_path, \
					&data->width, &data->height);
	data->e_img = mlx_xpm_file_to_image(data->mlx, data->e_path, \
					&data->width, &data->height);
	data->c_img = mlx_xpm_file_to_image(data->mlx, data->c_path, \
					&data->width, &data->height);
	data->g_img = mlx_xpm_file_to_image(data->mlx, data->g_path, \
					&data->width, &data->height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, data->enemy_path, \
					&data->width, &data->height);
	data->steps_img = mlx_xpm_file_to_image(data->mlx, data->steps_path, \
					&w_stepsbg, &h_stepsbg);
}

void	fullfill_map(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1')
				mlx_put_image_to_window(data->mlx, data->win, data->g_img, \
				j * WIMG, i * HIMG);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->w_img, \
				j * WIMG, i * HIMG);
			j++;
		}
		i++;
	}
}

void	fillmap_function(t_struct *data, int flag)
{
	char	*steps;

	if (flag == TRUE)
		create_imgs(data);
	else if (flag != FALSE)
		create_player(data);
	fullfill_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->p_img, \
	data->p_pos[0] * HIMG, data->p_pos[1] * WIMG);
	mlx_put_image_to_window(data->mlx, data->win, data->steps_img, 0, 0);
	mlx_string_put(data->mlx, data->win, 8, 14, \
		create_trgb(255, 255, 255, 255), "Steps: ");
	steps = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->win, 50, 14, \
		create_trgb(255, 255, 255, 255), steps);
	free(steps);
}

void	map_start(t_struct *data, int flag)
{
	int	i;
	int	j;

	fillmap_function(data, flag);
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, \
				data->c_img, j * HIMG, i * WIMG);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->e_img, \
				data->e_pos[0] * HIMG, data->e_pos[1] * WIMG);
			if (data->map[i][j] == 'N')
				mlx_put_image_to_window(data->mlx, data->win, data->enemy_img, \
				j * HIMG, i * WIMG);
		}
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
