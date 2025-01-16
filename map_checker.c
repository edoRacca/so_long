/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:08:39 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/16 15:01:18 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_finder(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->e_pos[0] = j;
				data->e_pos[1] = i;
			}
			j++;
		}
		i++;
	}
}

// Questa funzione trova la posizione del player all'interno della mappa
// e la salva all'interno di un array di interi nella struttura "data"
void	player_finder(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_pos[0] = j;
				data->p_pos[1] = i;
			}
			j++;
		}
		i++;
	}
}

int	check_accessible_map(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (data->map_copy[i][j] == 'C' || data->map_copy[i][j] == 'E'\
				|| data->map_copy[i][j] == 'P')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_objects(t_struct *data)
{
	int i;
	int	j;

	data->c_flag = 0;
	data->p_flag = 0;
	data->e_flag = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c_flag++;
			if (data->map[i][j] == 'E')
				data->e_flag++;
			if (data->map[i][j] == 'P')
				data->p_flag++;
			j++;
		}
		i++;
	}
	if (data->c_flag < 1 || data->e_flag != 1 || data->p_flag != 1)
		return (FALSE);
	return (TRUE);
}
