/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:54:11 by paminna           #+#    #+#             */
/*   Updated: 2021/01/12 21:33:31 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	int len;
	va_list arg;
	t_flags flags;
	const char *str;

	len = 0;
	va_start(arg, format);
	str = (char*)malloc(ft_strlen(format) + 1);
	str = format;
	while (str[len] != '\0')
	{
		while (str[len] != '%')
			write (1, &str[len++], 1);
		len++;
		ft_parser(str, &flags, len, arg);
	}
	va_end(arg);
	return (len);
}

int main()
{
	// ft_printf("Hello, %s", "world!");
	// ft_printf("Hello, %-08.*s", "world!");
	ft_printf("hello %c", 'c');
}