/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:54:11 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 20:38:15 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_process(t_flags *flags, va_list arg)
{
	if (flags->c == 'c')
		ft_process_char(flags, arg);
	else if (flags->c == 's')
		ft_process_string(flags, arg);
	else if (flags->c == 'd' || flags->c == 'i')
		ft_process_int(flags, arg);
	else if (flags->c == '%')
		ft_process_percent(flags);
	else if (flags->c == 'u')
		ft_process_u(flags, arg);
	else if (flags->c == 'x')
		ft_process_x(flags, arg);
	else if (flags->c == 'X')
		ft_process_bigx(flags, arg);
	else if (flags->c == 'p')
		ft_process_p(flags, arg);
	else
		return (0);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	t_flags	flags;

	i = 0;
	flags.len = 0;
	if (!format)
		return (0);
	va_start(arg, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ft_putchar(&flags, format[i++]);
		if (format[i] == '\0')
			break ;
		i++;
		ft_parser(&flags, &format[i], arg);
		while (format[i] != flags.c)
			i++;
		i++;
		if (!ft_process(&flags, arg))
			break ;
	}
	va_end(arg);
	return (flags.len);
}
