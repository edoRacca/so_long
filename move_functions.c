/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:55:35 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/19 11:40:46 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_struct *data)
{
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == '1')
		return ;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == 'E' \
		&& data->c_flag == 0)
		ft_cross_close(data);
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == 'C')
		data->c_flag--;
	data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] = '0';
	data->p_pos[COL]++;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] = '0';
	if (data->p_pos[ROW] == data->e_pos[ROW] && \
		data->p_pos[COL] - 1 == data->e_pos[COL])
		data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] = 'E';
	data->moves++;
	ft_printf("Moves count: %d\n", data->moves);
	map_start(data, FALSE);
}

void	move_left(t_struct *data)
{
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == '1')
		return ;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == 'E' \
		&& data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] = '0';
	data->p_pos[COL]--;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] = '0';
	if (data->p_pos[ROW] == data->e_pos[ROW] && \
		data->p_pos[COL] + 1 == data->e_pos[COL])
		data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] = 'E';
	data->moves++;
	ft_printf("Moves count: %d\n", data->moves);
	map_start(data, FALSE);
}

void	move_down(t_struct *data)
{
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == '1')
		return ;
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == 'E' \
		&& data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = '0';
	data->p_pos[ROW]++;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] = '0';
	if (data->p_pos[ROW] - 1 == data->e_pos[ROW] && \
		data->p_pos[COL] == data->e_pos[COL])
		data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] = 'E';
	data->moves++;
	ft_printf("Moves count: %d\n", data->moves);
	map_start(data, FALSE);
}

void	move_up(t_struct *data)
{
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == '1')
		return ;
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'E' \
		&& data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW] - 1][data->p_pos[ROW]] = '0';
	data->p_pos[ROW]--;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = '0';
	if (data->p_pos[ROW] + 1 == data->e_pos[ROW] && \
		data->p_pos[COL] == data->e_pos[COL])
		data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = 'E';
	data->moves++;
	ft_printf("Moves count: %d\n", data->moves);
	map_start(data, FALSE);
}
