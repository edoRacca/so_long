/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:08:57 by edraccan          #+#    #+#             */
/*   Updated: 2024/12/07 08:47:37 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unum_len(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_llnum_len(unsigned long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_num_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_hexa_len(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_print_hexa(char c, unsigned int n)
{
	if (n >= 16)
	{
		ft_print_hexa(c, n / 16);
		ft_print_hexa(c, n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 97), 1);
			else if (c == 'X')
				ft_putchar_fd((n - 10 + 65), 1);
		}
	}
}
