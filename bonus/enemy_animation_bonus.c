/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:26 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/22 14:18:49 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_enemy(t_struct *data)
{
	data->width = WIMG;
	data->height = HIMG;
	mlx_destroy_image(data->mlx, data->enemy_img);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, data->enemy_path, \
					&data->width, &data->height);
}

void	display_enemy(t_struct *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N')
				mlx_put_image_to_window(data->mlx, data->win, data->enemy_img, \
				j * HIMG, i * WIMG);
		}
	}
}

int	animate_sprites(t_struct *data)
{
	static int	i;

	if (i < 350)
	{
		data->enemy_path = ENEMYPATH1;
		create_enemy(data);
		display_enemy(data);
	}
	else if (i > 350 && i < 700)
	{
		data->enemy_path = ENEMYPATH2;
		create_enemy(data);
		display_enemy(data);
	}
	else if (i > 700 && i < 1050)
	{
		data->enemy_path = ENEMYPATH3;
		create_enemy(data);
		display_enemy(data);
	}
	else if (i > 1050)
		i = 0;
	i++;
	return (0);
}
