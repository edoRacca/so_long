/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:20:52 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/18 10:56:26 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* REVIEW 
** Questa funzione controlla in primis se le righe di tutta la matrice sono uguali
** Poi controlla che i muri siano composti da 1
** Controlla che ci siano almeno 1 C, solo 1 P e solo 1 E 
** Se passa tutti questi controlli la funzione restitusce TRUE(1)
*/
int	ft_map_parsing(t_struct *data)
{
	if(map_generator(data) == FALSE)
		return(FALSE);
	if (check_rows_len(data) == FALSE)
		return (FALSE);
	if (check_map_values(data) == FALSE)
		return (free_maps(data), FALSE);
	if (wall_checker(data->rows, data->cols - 1, data) == FALSE)
		return (free_maps(data), FALSE);
	if (check_objects(data) == FALSE)
		return (free_maps(data), FALSE);
	player_finder(data);
	exit_finder(data);
	get_img_path(data);
	path_finder(data, data->p_pos[1], data->p_pos[0]);
	if (check_accessible_map(data) == FALSE)
		return (free_maps(data), FALSE);
	return (TRUE);
}

/* REVIEW Questa funzione controlla che tutti i muri della mappa siano composti dal valore 1
** il numero di righe ed il numero di colonne vengono passati alla funzione come argomento
** se la mappa non passa il controllo viene restituito FALSE = 1
*/
int	wall_checker(size_t rows, size_t cols, t_struct *data)
{
	size_t	i;

	i = 0;
	while (i < cols)
	{
		if (data->map[0][i] != '1')
			return (FALSE);
		if (data->map[rows - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (data->map[i][0] != '1')
			return (FALSE);
		if (data->map[i][cols - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

//REVIEW - Questa funzione scannerizza la mappa e sostituisce a tutti gli 0 e lettere una X
		//usa la ricorsione, verifica le posizioni intorno alla casella in cui si trova e
		//se trova uno 0 oppure una lettera richiama se stessa su quella casella, se invece
		//trova un 1 oppure una X non fa nulla se non trasformare la casella attuale in X

void	path_finder(t_struct *data, int x, int y)
{ 
	if (x == data->rows || y == data->cols)
		return ;
	if (data->map_copy[x][y] == 'X' || data->map_copy[x][y] == '1')
		return ;
	data->map_copy[x][y] = 'X';
	path_finder(data, x + 1, y);
	path_finder(data, x - 1, y);
	path_finder(data, x, y + 1);
	path_finder(data, x, y - 1);
	return ;
}

int	check_rows_len(t_struct *data)
{
	size_t 	i;

	i = 0;
	while (data->map[i])
	{
		if (data->cols - 1 != (int)ft_strlen(data->map[i]))
			return (free_maps(data), FALSE);
		i++;
	}
	return (TRUE);
}

int	check_map_values(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'E' && data->map[i][j] != 'P' && \
			data->map[i][j] != 'C' && data->map[i][j] != '0' && \
			data->map[i][j] != '1')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
