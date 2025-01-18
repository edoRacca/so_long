/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:55:35 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/18 11:55:55 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_struct *data)
{
	if (data->map[data->p_pos[1]][data->p_pos[0] + 1] == '1')
		return ;
	if (data->map[data->p_pos[1]][data->p_pos[0] + 1] == 'C')
		data->c_flag++;
	data->map[data->p_pos[1]][data->p_pos[0] + 1] = '0';
	data->p_pos[0]++;
	data->map[data->p_pos[1]][data->p_pos[0]] = 'P';
	data->map[data->p_pos[1]][data->p_pos[0] - 1] = '0';
	map_start(data);
}

void	move_left(t_struct *data)
{
	if (data->map[data->p_pos[1]][data->p_pos[0] - 1] == '1')
		return ;
	if (data->map[data->p_pos[1]][data->p_pos[0] - 1] == 'C')
		data->c_flag--;
	data->map[data->p_pos[1]][data->p_pos[0] - 1] = '0';
	data->p_pos[0]--;
	data->map[data->p_pos[1]][data->p_pos[0]] = 'P';
	data->map[data->p_pos[1]][data->p_pos[0] + 1] = '0';
	map_start(data);
}

void	move_down(t_struct *data)
{
	if (data->map[data->p_pos[1] + 1][data->p_pos[0]] == '1')
		return ;
	if (data->map[data->p_pos[1] + 1][data->p_pos[0]] == 'C')
		data->c_flag--;
	data->map[data->p_pos[1] + 1][data->p_pos[0]] = '0';
	data->p_pos[1]++;
	data->map[data->p_pos[1]][data->p_pos[0]] = 'P';
	data->map[data->p_pos[1] - 1][data->p_pos[0]] = '0';
	map_start(data);
}

void	move_up(t_struct *data)
{
	if (data->map[data->p_pos[1] - 1][data->p_pos[0]] == '1')
		return ;
	if (data->map[data->p_pos[1] - 1][data->p_pos[0]] == 'C')
		data->c_flag--;
	data->map[data->p_pos[1] - 1][data->p_pos[0]] = '0';
	data->p_pos[1]--;
	data->map[data->p_pos[1]][data->p_pos[0]] = 'P';
	data->map[data->p_pos[1] + 1][data->p_pos[0]] = '0';
	map_start(data);
}
