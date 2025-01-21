/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:55:35 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/21 10:56:33 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	move_right(t_struct *data, int key)
{
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] + 1] == '1')
		return ;
	get_img_path(data, key);
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
	ft_printf("Steps: %d\n", data->moves);
	map_start(data, 2);
}

void	move_left(t_struct *data, int key)
{
	if (data->map[data->p_pos[ROW]][data->p_pos[COL] - 1] == '1')
		return ;
	get_img_path(data, key);
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
	ft_printf("Steps: %d\n", data->moves);
	map_start(data, 2);
}

void	move_down(t_struct *data, int key)
{
	if (data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] == '1')
		return ;
	get_img_path(data, key);
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
	ft_printf("Steps: %d\n", data->moves);
	map_start(data, 2);
}

void	move_up(t_struct *data, int key)
{
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == '1')
		return ;
	get_img_path(data, key);
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'C')
		data->c_flag--;
	if (data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] == 'E' \
		&& data->c_flag == 0)
		ft_cross_close(data);
	data->map[data->p_pos[ROW] - 1][data->p_pos[COL]] = '0';
	data->p_pos[ROW]--;
	data->map[data->p_pos[ROW]][data->p_pos[COL]] = 'P';
	data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = '0';
	if (data->p_pos[ROW] + 1 == data->e_pos[ROW] && \
		data->p_pos[COL] == data->e_pos[COL])
		data->map[data->p_pos[ROW] + 1][data->p_pos[COL]] = 'E';
	data->moves++;
	ft_printf("Steps: %d\n", data->moves);
	map_start(data, 2);
}
