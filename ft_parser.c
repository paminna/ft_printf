/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:06:24 by paminna           #+#    #+#             */
/*   Updated: 2021/01/12 22:50:25 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags ft_initialize(t_flags  *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->type = 0;
	flags->width = 0;
	flags->star_width = 0;
	flags->star= 0;
	flags->precision = -1;
	flags->space = 0;
	flags->sharp = 0;
	flags->plus = 0;
	flags->c = 0;
	return (*flags);
}

t_flags ft_parse_flags(t_flags *flags, const char *str, int *len, va_list arg)
{
	int i;
	char *c;

	i = *len;
	ft_initialize(flags);
	while (ft_strchr("cspdiuxX%", str[i]) != NULL)
	{
		// флаг пробел (бонус)
		// if (str[i] == ' ')
		// 	flags->space++;
		// флаги - и 0	
		while (str[i] == '-' || str[i] == 0)
		{
			if (str[i] == '-')
				flags->minus = 1;
			else if (str[i] == 0)
				flags->zero = 1;
			i++;
		}
		if (flags->zero == 1 && flags->minus == 1)
			flags->zero = 0;
		if (str[i] == '.')
		{
			if (str[i + 1] == '*')
			{
				flags->precision = va_arg(arg, int);
				i++;
			}
			else
			{
				flags->precision = 0;
				while (str[i] >= 0 && str[i] <= 9)
					flags->precision = str[i++];
			}
		}
		if (str[i] == '*')
		{	
			flags->star = 1;
			flags->width = va_arg(arg, int);
			if (flags->width < 0)
			{
				flags->minus = 1;
				flags->width = flags->width * (-1);
				flags->zero = 0;
			}
		}
		if (str[i] >= 0 && str[i] <= 9)
		{
			if (flags->star == 1)
				flags->width = 0;
			flags->width = flags->width * 10 + '0';
		}
			//my
		// // ширина
		// if ((str[i] >= 0 && str[i] <= 9) && (str[i - 1] != '.'))
		// 	flags->width = str[i] * 10 + '0';
		// else if (str[i] == '*')
		// 	flags->star_width = va_arg(arg, int);
		// // точность
		// if (str[i] >= 0 && str[i] <= 9 && str[i - 1] == '.')
		// 	flags->precision = str[i];
		// else if (str[i] == '*' && str[i - 1] == '.')
		// 	flags->star = va_arg(arg, int);
		// else if ((!(str[i] >= 0 && str[i] <= 9) && !(str[i] == '*')) && (str[i - 1] != '.'))
		// 	flags->precision = 0;
		i++;
	}
	// тип
	if ((c = ft_strchr("cspdiuxX%", str[i])) != NULL)
		flags->c = (char)c;
	return (*flags);
}

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

int ft_parser(const char *str, t_flags *flags, int len, va_list arg)
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