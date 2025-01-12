/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:46 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/12 23:36:34 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_struct	data;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid arguments.");
		return (0);
	}
	data.path = av[1];
	if (ft_map_parsing(&data) == FALSE)
	{
		ft_printf("Error\nInvalid map");
		return (0);
	}
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MALLOC_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "corbezzoli!");
	mlx_hook(data.win, 17, 1L << 0, ft_cross_close, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_close, &data);
	mlx_loop(data.mlx);
}