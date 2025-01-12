/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:04 by lparolis          #+#    #+#             */
/*   Updated: 2025/01/12 15:29:41 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eder.h"

// Questa funzione fa in modo che premendo il tasto esc la finestra
// si chiuda
int	ft_close(int key, t_struct *data)
{
	// ft_printf("%d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		spread_democracy(data);
		exit (0);
	}
	return (0);
}

// Questa funzione fa in modo che quando schiacci la croce in alto a destra
// dell finestra la finestra si chiuda
int ft_cross_close(t_struct *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	spread_democracy(data);
	exit(0);	
}