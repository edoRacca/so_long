/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:33:13 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/13 15:18:39 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Una funzione che usando gnl si crea un array di puntatori contenente la  mappa
// (contenuto all'interno della solita struttura "data")
// alloca anche lo spazio per ogni stringa prima di assegnarla, usando calloc per
// evitare problemi di terminazione con carattere nullo o leak
int	map_generator(t_struct *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	i = 0;
	line = get_next_line(fd);
	alloc_map(data);
	while (line)
	{
		data->map[i] = ft_strdup(line);
		if (ft_strchr(line, '\n'))	
			data->map[i][ft_strlen(line) - 1] = '\0';
		ft_printf("%s\n", data->map[i]);
		if (line)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	map_copy(data);
	return (TRUE);
}

// Funzione che alloca la memoria per il puntatore base del puntatore
// di puntatori dove verra copiata la mappa
// utilizzo calloc per evitare di dover assegnare lo /0 ogni volta e per
// evitare eventuali memory leak
int	alloc_map(t_struct *data)
{
	int		fd;
	int		row;
	int 	col;
	char	*line;

	fd = open(data->path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	col = 0;
	line = get_next_line(fd);
	row = ft_strlen(line);
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		col++;
	}
	data->map = ft_calloc(((row * col) + 1), sizeof(char *));
	data->map_copy = ft_calloc(((row * col) + 1), sizeof(char *));
	data->map[col] = NULL;
	data->map_copy[col] = NULL;
	return (TRUE);
}

// Questa funzione mi va a dichiarare la copia della mappa nella struttura "data"
// il puntatore principale di map_copy e' gia' stato creato in map map_generator
// questa funzione va solo ad inizializzare i puntatori delle righe
void	map_copy(t_struct *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		data->map_copy[i] = ft_strdup(data->map[i]);
		ft_printf("%s %d\n", data->map_copy[i], i);
		i++;
	}
}

// Questa funzione mi va a liberare il contenuto della struttura
void	free_maps(t_struct	*data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		free(data->map[i]);
		free(data->map_copy[i]);
		i++;
	}
	free(data->map);
	free(data->map_copy);
}

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
				ft_printf("%c", data->map[i][j]);
			}
			j++;
		}
		i++;
	}	
}