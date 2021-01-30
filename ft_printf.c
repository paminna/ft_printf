/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:54:11 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 14:34:07 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_process(t_flags *flags, va_list arg)
{
	if (flags->c == 'c')
		ft_process_char(flags, arg);
	if (flags->c == 's')
		ft_process_string(flags, arg);
	if (flags->c == 'd' || flags->c == 'i')
		ft_process_int(flags, arg);
	if (flags->c == '%')
		ft_process_percent(flags);
	if (flags->c == 'u')
		ft_process_u(flags, arg);
	if (flags->c == 'x')
		ft_process_x(flags, arg);
	if (flags->c == 'X')
		ft_process_X(flags, arg);
	if (flags->c == 'p')
		ft_process_p(flags, arg);
}

int ft_printf(const char *format, ...)
{
	int i;
	va_list arg;
	t_flags flags;

	i = 0;
	flags.len = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ft_putchar(&flags, format[i++]);
		if (format[i] == '\0')
			break;
		i++;
		ft_parser(&flags, &format[i], arg);
		while (format[i] != flags.c)
			i++;
		i++;
		ft_process(&flags, arg);
	}
	va_end(arg);
	return (flags.len);
}