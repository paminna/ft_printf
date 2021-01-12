/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:52:51 by paminna           #+#    #+#             */
/*   Updated: 2021/01/12 22:55:00 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_add_spaces(const char *str, int len, t_flags *flags)
{
	char *s;
	int i;

	i = 0;
	s = (char*)malloc(flags->width + flags->precision + sizeof(str) + 1);
	if (s == NULL)
		return (NULL);
	while (flags->width != 0)
	{
		s[i++] = ' ';
		flags->width--;
	}
	while (str != '\0')
	{
		s[i] = str[len];
		i++;
		len++;
	}
	return (s);
}

int ft_process(const char *str, t_flags *flags, int len, va_list arg)
{
	char space;

	space = ' ';
	*flags = ft_parse_flags(flags, str, &len, arg);
	if (flags->c == 'c')
	{
		if (flags->minus == 1 && flags->width != 0)
		{
			write(1, &str[len], 1);
			while (flags->width != 0)
			{
				len++;
				write(1, &space, 1);
				flags->width--;
			}
		}
		else 
			write(1, &str[len++], 1);
	}
	if (flags->c == 's')
	{
		// if (str == NULL)
			//return(NULL);
		if (flags->precision >= 0 && flags->precision > ft_strlen(str))
			flags->precision = ft_strlen(str);
		if (flags->minus == 1)
		{
			if (flags->precision >= 0)
			{
				if (flags->width != 0)
				{
					str = ft_add_spaces(str, len, flags);
					if (str == NULL)
						return (-1);
					len++;
				}
			}
			else
			{
				//
			}
		}
		else
		{
			if (flags->precision >= 0)
			{

			}
		}
	}
	if (flags->c == 'p')
	{
	}
	return (len);
}