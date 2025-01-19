/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:46 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/19 16:59:19 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_img(t_struct *data)
{
	if (!data->p_path || !data->c_path || !data->e_path || !data->g_path)
	{
		ft_printf("Error\nInvalid image path\n");
		return (FALSE);
	}
	return (TRUE);
}

int	check_file_extension(t_struct *data)
{
	char	*str;

	str = ft_strchr(data->map_path, '.');
	if (str)
		if (ft_strncmp(str, ".ber", 4) == 0)
			return (TRUE);
	return (FALSE);
}

// Questa funzione fa in modo che quando schiacci la croce in alto a destra
// dell finestra la finestra si chiuda
int	ft_cross_close(t_struct *data)
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
	exit(0);
}

int	main(int ac, char **av)
{
	t_struct	data;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid arguments.");
		return (0);
	}
	data.map_path = av[1];
	if (check_file_extension(&data) == FALSE || ft_map_parsing(&data) == FALSE)
	{
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	if (check_valid_img(&data) == FALSE)
		return (0);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MALLOC_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH * (data.cols - 1), \
						HEIGHT * data.rows, "GOTTA CATCH 'EM ALL");
	map_start(&data, TRUE);
	mlx_hook(data.win, 17, 1L << 0, ft_cross_close, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_render, &data);
	mlx_loop(data.mlx);
}
