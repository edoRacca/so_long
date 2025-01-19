/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_steps_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:11:28 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/19 18:30:11 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(t_struct *data)
{
	int	wsteps;

	wsteps = data->width * 2;
	data->steps_img = mlx_xpm_file_to_image(data->mlx, data->steps_path, \
					&wsteps, &data->height);
	mlx_put_image_to_window(data->mlx, data->win, data->steps_img, 0, HEIGHT * data->rows);
}