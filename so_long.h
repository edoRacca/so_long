/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:36:11 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/17 19:16:11 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MALLOC_ERROR 1
# define WIDTH 48
# define HEIGHT 48
# define HIMG HEIGHT
# define WIMG WIDTH
# define TRUE 1
# define FALSE 0

# include "./minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_struct
{
	void	*mlx;
	void	*win;
	char	*map_path;
	char	**map;
	char	**map_copy;
	char	*p_path;
	void	*p_img;
	int		p_wimg;
	int		p_himg;
	char	*e_path;
	char	*e_img;
	int		e_wimg;
	int		e_himg;
	char	*c_path;
	char	*c_img;
	int		c_wimg;
	int		c_himg;
	char	*w_path;
	char	*w_img;
	int		w_wimg;
	int		w_himg;
	int		rows;
	int		cols;
	int		p_pos[2];
	int		e_pos[2];
	int		p_flag;
	int		c_flag;
	int		e_flag;
}				t_struct;

int		ft_render(int key, t_struct *data);
int 	ft_cross_close(t_struct *data);
int		map_generator(t_struct *data);
int		alloc_map(t_struct *data);
void	get_img_path(t_struct *data);
int		map_generator(t_struct *data);
int		wall_checker(size_t rows, size_t cols, t_struct *data);
int		ft_map_parsing(t_struct *data);
void	free_maps(t_struct	*data);
void	map_copy(t_struct *data);
void	exit_finder(t_struct *data);
void	player_finder(t_struct *data);
void	path_finder(t_struct *data, int x, int y);
int		check_rows_len(t_struct *data);
int		check_map_values(t_struct *data);
int		check_accessible_map(t_struct *data);
int		check_objects(t_struct *data);

void	fullfill_map(t_struct *data);
void	create_imgs(t_struct *data);
void	map_start(t_struct *data);

#endif