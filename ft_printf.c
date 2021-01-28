/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@stud.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:54:11 by paminna           #+#    #+#             */
/*   Updated: 2021/01/27 17:43:10 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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