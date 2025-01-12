/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:41:41 by edraccan          #+#    #+#             */
/*   Updated: 2024/12/05 09:01:56 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ll(unsigned long long n)
{
	if (n >= 16)
	{
		ft_print_ll(n / 16);
		ft_print_ll(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, 1);
		else
			ft_putchar_fd((n - 10 + 97), 1);
	}
}

void	ft_putnbr_uns(unsigned int n)
{
	char	c;

	if (n / 10)
		ft_putnbr_fd(n / 10, 1);
	c = '0' + n % 10;
	ft_putchar_fd(c, 1);
}
