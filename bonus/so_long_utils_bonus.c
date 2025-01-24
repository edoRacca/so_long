/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:58:43 by edraccan          #+#    #+#             */
/*   Updated: 2025/01/24 10:54:45 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_file_extension(t_struct *data)
{
	char	*str;

	str = ft_strchr(data->map_path, '.');
	if (str)
		if (ft_strncmp(str, ".ber", 4) == 0 && str[4] == '\0')
			return (TRUE);
	return (FALSE);
}
