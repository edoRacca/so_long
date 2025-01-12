/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:54:25 by edraccan          #+#    #+#             */
/*   Updated: 2024/12/05 10:25:46 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* SECTION 
** ft_printf.c
*/
int		ft_printf(const char *s, ...);
int		chose_flag(char c, va_list arg);

/* SECTION 
** ft_format_print.c
*/
int		format_point(unsigned long long n);
int		format_uns(unsigned int n);
int		format_hexa(char c, int n);
int		format_int(int n);
int		format_string(char *str);

int		ft_unum_len(unsigned int n);
int		ft_llnum_len(unsigned long long n);
int		ft_num_len(int n);
int		ft_hexa_len(unsigned int n);
void	ft_print_hexa(char c, unsigned int n);

void	ft_print_ll(unsigned long long n);
void	ft_putnbr_uns(unsigned int n);

#endif