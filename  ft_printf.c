/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:06:28 by paminna           #+#    #+#             */
/*   Updated: 2021/01/11 22:32:50 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	int len;
	va_list arg;
	t_flags flags;

	len = 0;
	va_start(arg, format);
	while (format[len] != '\0')
	{
		while (format[len] != '%')
			write (1, &format[len++], 1);
		ft_parser(format, &flags, len, arg);
	}
	va_end(arg);
	return (len);
}

int main()
{
	// ft_printf("Hello, %s", "world!");
	// ft_printf("Hello, %-08.*s", "world!");
	printf("hello %-8s", "ew");
}