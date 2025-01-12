/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:33:27 by lparolis          #+#    #+#             */
/*   Updated: 2025/01/11 10:27:332 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eder.h"

//TODO Check da fare:
	// -Lunghezza righe tutte uguali
	// -colonne tutte uguali
	// -Num righe diverso da colonne
	// -Controllo muri (righe e colonne esterne tutte 1)
	// -Controllo di un percorso valido all'interno della mappa

// REVIEW Questa funzione controlla in primis se le righe di tutta la matrice sono uguali tra di
		// loro, in caso contrario ritorna FALSE = 1
		// Sucessivamente controlla se la mappa e' rettangolare, ossia che il numero di righe sia
		// diverso dal numero di colonne
		// Se passa questi controlli richiama una funzione che controlla se i muri della mappa
		// sono tutti composti dal numero 1
		// Se la mappa passa tutti questi controlli la funzione restitusce TRUE = 1

int	ft_map_parsing(t_struct *data)
{
	size_t	row_length;
	size_t 	i;

	i = 0;
	if(map_generator(data) == FALSE)
		return(FALSE);
	row_length = ft_strlen(data->map[0]);
	data->cols = row_length;
	while (data->map[i])
	{
		if (row_length != ft_strlen(data->map[i]))
			return (FALSE);
		i++;
	}
	i = 0;
	while (data->map[i])
		i++;
	data->rows = i + 1;
	if (i == row_length)
		return (FALSE);
	if (wall_checker(i, row_length, data) == FALSE)
		return (FALSE);
	return (TRUE);
}
//REVIEW Questa funzione controlla che tutti i muri della mappa siano composti dal valore 1
		// il numero di righe ed il numero di colonne vengono passati alla funzione come argomento
		// se la mappa non passa il controllo viene restituito FALSE = 1

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

void	pathfinder(t_struct *data, int x, int y)
{ 
	data->map_copy[x][y] == 'X';
	if (data->map_copy[x - 1][y] != '1' || data->map_copy[x - 1][y] != 'X')
	{
		pathfinder(&data, x - 1, y);
	}
	
}
