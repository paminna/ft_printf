/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@stud.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:20:10 by paminna           #+#    #+#             */
/*   Updated: 2021/01/27 23:58:33 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_process_char(t_flags *flags, va_list arg)
{
	int ch;
	
	ch = va_arg(arg, int);
	if (flags->minus == 1 && flags->width != 0)
	{
		ft_putchar(flags, (char)ch);
		while (flags->width - 1!= 0)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
	}
	else 
	{
		while (flags->width - 1 != 0)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
		ft_putchar(flags, (char)ch);
	}
}

int ft_process_string_help(t_flags *flags, char *s)
{
	int i;

	i = 0;
	if (flags->width != 0)
		flags->width= flags->width - flags->precision;
	while (flags->precision > 0)
	{
		ft_putchar(flags, s[i++]);
		flags->precision--;
	}
	if (flags->width != 0)
	{
		while (flags->width != 0)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
	}
	return(i);
}

int ft_process_string_help_2(t_flags *flags, char *s)
{
	int i;

	i = 0;
	if (flags->width != 0)
		flags->width= flags->width - flags->precision;
	if (flags->width != 0)
	{
		while (flags->width != 0)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
	}
	while (flags->precision > 0)
	{
		ft_putchar(flags, s[i++]);
		flags->precision--;
	}
	return(i);
}

void ft_process_string(t_flags *flags, va_list arg)
{
	char *s;
	int i;
	int size;

	i = 0;
	s = va_arg(arg, char*);
	size = ft_strlen(s);
	if (s == NULL)
		s = "(null)";
	if (flags->precision >= 0 && flags->precision > size)
		flags->precision = size;
	while (flags->width - size > 0 && flags->precision == -1) 
	{
		ft_putchar(flags, ' ');
		flags->width--;
	}
	if (flags->minus == 1)
	{
		if (flags->precision >= 0)
		{
			i = ft_process_string_help(flags, &s[i]);
			return;
		}
	}
	else
	{
		i = ft_process_string_help_2(flags, &s[i]);
		return;
	}
	while (s[i] != '\0')
		ft_putchar(flags, s[i++]);
}