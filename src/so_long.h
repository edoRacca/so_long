/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:36:11 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/24 12:38:24 by edraccan         ###   ########.fr       */
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
# define ROW 1
# define COL 0

# define T_RED "\033[31m"
# define T_GREEN "\033[32m"
# define T_YELLOW "\033[33m"
# define T_BLUE "\033[34m"
# define T_WHITE "\033[0m"
# define B_RED "\033[41m"
# define B_GREEN "\033[42m"
# define B_BLUE "\033[44m"

# define CPATH "textures/masterball_ground.xpm"
# define PPATH_L "textures/Garchomp_left_ground.xpm"
# define PPATH_R "textures/Garchomp_right_ground.xpm"
# define PPATH_U "textures/Garchomp_up_ground.xpm"
# define PPATH_D "textures/Garchomp_down_ground.xpm"
# define EPATH_R "textures/pokeball48_right.xpm"
# define EPATH_L "textures/pokeball48_left.xpm"
# define GPATH "textures/grass2.xpm"
# define WPATH "textures/tree_wall_ground.xpm"
# define STEPSPATH "textures/Steps.xpm"

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
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
	char	*e_path;
	char	*e_img;
	char	*c_path;
	char	*c_img;
	char	*g_path;
	char	*g_img;
	char	*w_path;
	char	*w_img;
	char	*steps_path;
	char	*steps_img;
	int		width;
	int		height;
	int		rows;
	int		cols;
	int		p_pos[2];
	int		e_pos[2];
	int		p_flag;
	int		c_flag;
	int		e_flag;
	int		temp_flag;
	int		exit_flag;
	int		moves;
}				t_struct;

// so_long.c
int		check_file_extension(t_struct *data);
int		ft_cross_close(t_struct *data);

// render.c
void	create_player(t_struct *data);
int		ft_render(int key, t_struct *data);

// map_utils.c
void	get_img_path(t_struct *data, int key);
int		map_generator(t_struct *data);
int		alloc_map(t_struct *data);
void	free_maps(t_struct	*data);
void	map_copy(t_struct *data);

// map_parsing.c
int		wall_checker(size_t rows, size_t cols, t_struct *data);
int		ft_map_parsing(t_struct *data);
void	path_finder(t_struct *data, int x, int y);
int		check_rows_len(t_struct *data);
int		check_map_values(t_struct *data);

// map_checker.c
void	exit_finder(t_struct *data);
void	player_finder(t_struct *data);
int		check_accessible_map(t_struct *data);
int		check_objects(t_struct *data);

// display_map.c
void	create_imgs(t_struct *data);
void	fullfill_map(t_struct *data);
void	fillmap_function(t_struct *data, int flag);
void	map_start(t_struct *data, int flag);
void	print_map(t_struct *data);

// move_functions.c
void	move_right(t_struct *data, int key);
void	move_left(t_struct *data, int key);
void	move_down(t_struct *data, int key);
void	move_up(t_struct *data, int key);

#endif