/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:08:39 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/13 18:09:29 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Questa funzione trova la posizione del player all'interno della mappa
// e la salva all'interno di un array di interi nella struttura "data"
void	player_finder(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j] != '\0')
	{
		while (data->map[i][j] != '\0')
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
