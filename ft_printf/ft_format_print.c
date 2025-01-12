/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:57 by edraccan          #+#    #+#             */
/*   Updated: 2024/12/07 08:49:23 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_point(unsigned long long n)
{
	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	ft_putstr_fd("0x", 1);
	ft_print_ll(n);
	return (ft_llnum_len(n) + 2);
}

int	format_uns(unsigned int n)
{
	ft_putnbr_uns(n);
	return (ft_unum_len(n));
}

int	format_hexa(char c, int n)
{
	ft_print_hexa(c, (unsigned int)n);
	return (ft_hexa_len(n));
}

int	format_int(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_num_len(n));
}

int	format_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
