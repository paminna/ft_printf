/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:20:10 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 19:34:36 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_char(t_flags *flags, va_list arg)
{
	int ch;

	ch = va_arg(arg, int);
	if (flags->minus == 1)
		ft_putchar(flags, (char)ch);
	if (flags->width != 0)
	{
		while (flags->width - 1 != 0)
		{
			if (flags->width > 0)
				ft_putchar(flags, ' ');
			if (flags->zero == 1)
				ft_putchar(flags, '0');
			flags->width--;
		}
	}
	if (flags->minus == 0)
		ft_putchar(flags, (char)ch);
}

void	ft_process_string(t_flags *flags, va_list arg)
{
	char	*s;
	int		i;
	int		size;

	i = 0;
	s = va_arg(arg, char*);
	if (s == NULL)
		s = "(null)";
	size = ft_strlen(s);
	if (flags->precision >= 0 && flags->precision < size)
		size = flags->precision;
	if (flags->width > size && flags->minus == 0)
		while (flags->width != size)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
	while (i != size)
		ft_putchar(flags, s[i++]);
	if (flags->minus == 1 && flags->width > size)
		while (flags->width != size)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
}

void	ft_process_percent(t_flags *flags)
{
	char ch;

	ch = '%';
	if (flags->minus == 1)
		ft_putchar(flags, ch);
	if (flags->width != 0)
	{
		while (flags->width - 1 != 0)
		{
			if (flags->width > 0 && flags->zero == 0)
				ft_putchar(flags, ' ');
			if (flags->zero == 1)
				ft_putchar(flags, '0');
			flags->width--;
		}
	}
	if (flags->minus == 0)
		ft_putchar(flags, ch);
}
