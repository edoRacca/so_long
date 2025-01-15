/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:33:13 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/15 18:01:12 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img_path(t_struct *data)
{
	data->c_path = "textures/";
	data->e_path = "textures/";
	data->p_path = "textures/Slowbro.xpm";
}

// Una funzione che usando gnl si crea un array di puntatori contenente la  mappa
// (contenuto all'interno della solita struttura "data")
// alloca anche lo spazio per ogni stringa prima di assegnarla, usando calloc per
// evitare problemi di terminazione con carattere nullo o leak
int	map_generator(t_struct *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	get_img_path(data);
	i = 0;
	alloc_map(data);
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strdup(line);
		if (ft_strchr(line, '\n'))	
			data->map[i][ft_strlen(line) - 1] = '\0';
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
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	data->rows = 0;
	line = get_next_line(fd);
	data->cols = ft_strlen(line);
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		data->rows++;
	}
	data->map = ft_calloc(((data->rows * data->cols) + 1), sizeof(char *));
	data->map_copy = ft_calloc(((data->rows * data->cols) + 1), sizeof(char *));
	data->map[data->rows] = NULL;
	data->map_copy[data->rows] = NULL;
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
		i++;
	}
}

// Questa funzione mi va a liberare il contenuto della struttura
void	free_maps(t_struct	*data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		free(data->map_copy[i]);
		i++;
	}
	free(data->map);
	free(data->map_copy);
}
