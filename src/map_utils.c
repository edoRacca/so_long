/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:33:13 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/20 18:17:00 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img_path(t_struct *data, int key)
{
	data->c_path = CPATH;
	data->w_path = WPATH;
	if (data->e_pos[0] <= data->cols / 2)
		data->e_path = EPATH_L;
	else
		data->e_path = EPATH_R;
	if (key == XK_Up || key == XK_w || key == XK_q)
		data->p_path = PPATH_U;
	else if (key == XK_Left || key == XK_a || key == XK_s)
		data->p_path = PPATH_L;
	else if (key == XK_Right || key == XK_d || key == XK_d)
		data->p_path = PPATH_R;
	else
		data->p_path = PPATH_D;
	data->g_path = GPATH;
}

/* NOTE
** Una funzione che usa gnl e crea una matrice contenente la mappa.
** Alloca anche lo spazio per ogni stringa prima di assegnarla per
** evitare problemi di terminazione con carattere nullo
*/
int	map_generator(t_struct *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
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

/* NOTE
** Questa funzione dichiara la copia della mappa nella struttura "data"
*/
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
