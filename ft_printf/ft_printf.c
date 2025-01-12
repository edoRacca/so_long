/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:09:36 by edraccan          #+#    #+#             */
/*   Updated: 2024/12/07 15:53:04 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chose_flag(char c, va_list arg)
{
	int		cont;

	cont = 0;
	if (c == '%' || c == 'c')
	{
		if (c == '%')
			ft_putchar_fd('%', 1);
		else
			ft_putchar_fd(va_arg(arg, int), 1);
		cont++;
	}
	else if (c == 's')
		cont = format_string(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		cont = format_int(va_arg(arg, int));
	else if (c == 'x' || c == 'X')
		cont = format_hexa(c, va_arg(arg, unsigned int));
	else if (c == 'u')
		cont = format_uns(va_arg(arg, unsigned int));
	else if (c == 'p')
		cont = format_point(va_arg(arg, unsigned long long));
	return (cont);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		cont;

	va_start(arg, s);
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			cont += chose_flag(s[i + 1], arg);
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			cont++;
			i++;
		}
	}
	va_end(arg);
	return (cont);
}

/* 
int main()
{
	// char *s = NULL;
	
	// printf("return printf [c]: %d\n", printf("ciao %c - ", 'p'));
	// printf("return ft_printf [c]: %d\n", ft_printf("ciao %c - ", 'p'));
	// printf("return printf [%%]: %d\n", printf("ciao %% - "));
	// printf("return ft_printf [%%]: %d\n", ft_printf("ciao %% - "));
	// printf("return printf [s]: %d\n", printf("ciao %s - ", s));
	// printf("return ft_printf [s]: %d\n", ft_printf("ciao %s - ", s));
	// printf("return printf [d]: %d\n", printf("ciao %d - ", 012));
	// printf("return ft_printf [d]: %d\n", ft_printf("ciao %d - ", 012));
	// printf("return printf [i]: %d\n", printf("ciao %i - ", 012));
	// printf("return ft_printf [i]: %d\n", ft_printf("ciao %i - ", 012));
	// printf("return printf [x]: %d\n", printf("|ciao %x - |", -3));
	// printf("return ft_printf [x]: %d\n", ft_printf("|ciao %x - |", -3));
	// printf("RETURN: fffffffd");
	// printf("return printf [X]: %d\n", printf("ciao %X - ", -2));
	// printf("return ft_printf [X]: %d\n", ft_printf("ciao %X - ", -2));
	// printf("return printf [u]: %d\n", printf("ciao %u - ", -2));
	// printf("return ft_printf [u]: %d\n", ft_printf("ciao %u - ", -2));
	// printf("return printf [p]: %d\n", printf("ciao %p - ", NULL));
	// printf("return ft_printf [p]: %d\n", ft_printf("ciao %p - ", NULL));
} */