/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:46 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/24 12:15:40 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Questa funzione fa in modo che quando schiacci la croce in alto a destra
// dell finestra la finestra si chiuda
int	ft_cross_close(t_struct *data)
{
	mlx_destroy_image(data->mlx, data->p_img);
	mlx_destroy_image(data->mlx, data->e_img);
	mlx_destroy_image(data->mlx, data->c_img);
	mlx_destroy_image(data->mlx, data->g_img);
	mlx_destroy_image(data->mlx, data->w_img);
	mlx_destroy_image(data->mlx, data->steps_img);
	mlx_destroy_image(data->mlx, data->enemy_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_maps(data);
	exit(0);
}

int	main(int ac, char **av)
{
	t_struct	data;

	if (ac != 2)
		return (ft_printf("Error\nInvalid arguments.\n"), 0);
	data.map_path = av[1];
	if (check_file_extension(&data) == FALSE || ft_map_parsing(&data) == FALSE)
		return (ft_printf("Error\nInvalid map\n"), 0);
	if (WIDTH * (data.cols - 1) > 1920 || HEIGHT * data.rows > 1080)
		return (ft_printf("Error\nMap is too big (max %d x %d)\n", \
			1920 / WIDTH, 1080 / HEIGHT), 0);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MALLOC_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH * (data.cols - 1), \
			HEIGHT * data.rows, "GOTTA CATCH 'EM ALL");
	map_start(&data, TRUE);
	mlx_hook(data.win, 17, 1L << 0, ft_cross_close, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_render, &data);
	mlx_loop_hook(data.mlx, animate_sprites, &data);
	mlx_loop(data.mlx);
}
