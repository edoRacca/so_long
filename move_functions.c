/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:55:35 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/18 18:24:21 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_struct *data)
{
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == '1')
		return ;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == 'E' && data->c_flag != 0)
		data->temp_flag = 1;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == 'E' && data->c_flag == 0)
		ft_cross_close(data);
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == 'C')
		data->c_flag--;
	data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] = '0';
	data->p_pos[COL]++;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] = '0';
	if (data->exit_flag == 1)
	{
		data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] = 'E';
		data->exit_flag = 0;
	}
	if (data->temp_flag == 1)
	{
		data->exit_flag = 1;
		data->temp_flag = 0;
	}
	data->moves++;
	// ft_printf("Moves: %d\n", data->moves);
	map_start(data);
}

void	move_left(t_struct *data)
{
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == '1')
		return ;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == 'E' && data->c_flag != 0)
		data->temp_flag = 1;	
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == 'E' && data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] = '0';
	data->p_pos[COL]--;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] = '0';
	if (data->exit_flag == 1)
	{
		data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] = 'E';
		data->exit_flag = 0;
	}
	if (data->temp_flag == 1)
	{
		data->exit_flag = 1;
		data->temp_flag = 0;
	}
	data->moves++;
	// ft_printf("Moves: %d\n", data->moves);
	map_start(data);
}

void	move_down(t_struct *data)
{
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == '1')
		return ;
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == 'E' && data->c_flag != 0)
		data->temp_flag = 1;
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == 'E' && data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = '0';
	data->p_pos[ROW]++;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] = '0';
	if (data->exit_flag == 1)
	{
		data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] = 'E';
		data->exit_flag = 0;
	}
	if (data->temp_flag == 1)
	{
		data->exit_flag = 1;
		data->temp_flag = 0;
	}
	data->moves++;
	// ft_printf("Moves: %d\n", data->moves);
	map_start(data);
}

void	move_up(t_struct *data)
{
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == '1')
		return ;
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'E' && data->c_flag != 0)
		data->temp_flag = 1;
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'E' && data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW] - 1][data->p_pos[ROW]] = '0';
	data->p_pos[ROW]--;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = '0';
	if (data->exit_flag == 1)
	{
		data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = 'E';
		data->exit_flag = 0;
	}
	if (data->temp_flag == 1)
	{
		data->exit_flag = 1;
		data->temp_flag = 0;
	}
	data->moves++;
	// ft_printf("Moves: %d\n", data->moves);
	map_start(data);
}
