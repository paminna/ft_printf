/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:16:58 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 18:21:47 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_minus_help_2(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	if (s[i] == '-')
	{	
		ft_putchar(flags, s[i++]);
		size--;
	}
	if (s[i] == '0')
		flags->width--;
	while (flags->precision-- - size > 0)
		ft_putchar(flags, '0');
	while (flags->width-- > flags->precision && s[i] != '\0')
		ft_putchar(flags, s[i++]);
	while (flags->width - 2 > 0)
	{
		ft_putchar(flags, ' ');
		flags->width--;
	}
	*c = i;
}

void ft_minus_help(t_flags *flags, char *s, int *i, int size)
{
	int c;

	c = *i;
	if (s[c] == '0' && flags->precision == 0)
	{
		size = 0;
		s[c] = '\0';
	}
	if (flags->precision > size)
		ft_minus_help_2(flags, s, &c, size);
	else 
	{
		while (flags->width - size > 0 && s[c] != '\0')
			ft_putchar(flags, s[c++]);
		while (flags->width - size > 0)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
	}
	if (flags->precision == size && s[c] == '-')
	{
		if (s[c] == '-')
		{
			ft_putchar(flags, '-');
			c++;
			flags->precision++;
		}
		while (flags->precision-- - size > 0)
			ft_putchar(flags, '0');
	}
	*i = c;
}

void ft_positive_help_2(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	if (s[i] == '-')
		flags->width--;
	while (flags->width--  > flags->precision)
		ft_putchar(flags, ' ');
	if (s[i] == '-')
	{	
		ft_putchar(flags, s[i++]);
		size--;
	}
	while (flags->precision-- - size > 0)
		ft_putchar(flags, '0');
	*c = i;
}

void ft_positive_help(t_flags *flags, char *s, int *i, int size)
{
	int c;

	c = *i;
	if (s[c] == '0' && flags->precision == 0)
	{
		size = 0;
		s[c] = '\0';
	}
	if (flags->precision - size > 0)
		ft_positive_help_2(flags, s, &c, size);
	else if (flags->zero == 1 && flags->width - size > 0)
	{
		if (s[c] == '-')
		{
			ft_putchar(flags, '-');
			c++;
		}
		while (flags->width-- - size > 0)
			ft_putchar(flags, '0');
	}
	else while (flags->width-- - size > 0)
		ft_putchar(flags, ' ');
	if (flags->precision == size && s[c] == '-')
	{
		if (s[c] == '-')
		{
			ft_putchar(flags, '-');
			c++;
			flags->precision++;
		}
		while (flags->precision-- - size > 0)
			ft_putchar(flags, '0');
	}
	*i = c;
}

void ft_process_int(t_flags *flags, va_list arg)
{
	int i;
	char *s;
	int size;

	s = ft_itoa(va_arg(arg, int));
	i = 0;
	size = ft_strlen(s);
	if (flags->minus == 1)
		ft_minus_help(flags, s, &i, size);
	if (flags->minus == 0)
		ft_positive_help(flags, s, &i, size);
	while (s[i] != '\0')
		ft_putchar(flags, s[i++]);
	free(s);
}