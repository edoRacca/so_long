/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:36:11 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/15 11:13:53 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MALLOC_ERROR 1
# define WIDTH 720
# define HEIGHT 480
# define TRUE 1
# define FALSE 0

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_struct
{
	void	*mlx;
	void	*win;
	char	*path;
	char	**map;
	char	**map_copy;
	int		rows;
	int		cols;
	int		p_pos[2];
	int		p_flag;
	int		c_flag;
	int		e_flag;
}				t_struct;

int		ft_close(int key, t_struct *data);
int 	ft_cross_close(t_struct *data);
int		map_generator(t_struct *data);
int		alloc_map(t_struct *data);
int		map_generator(t_struct *data);
int		wall_checker(size_t rows, size_t cols, t_struct *data);
int		ft_map_parsing(t_struct *data);
void	free_maps(t_struct	*data);
void	map_copy(t_struct *data);
void	player_finder(t_struct *data);
void	path_finder(t_struct *data, int x, int y);
int		check_rows_len(t_struct *data);
int		check_map_values(t_struct *data);
int		check_accessible_map(t_struct *data);
int		check_objects(t_struct *data);

#endif