/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:06:24 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 20:16:29 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_minus(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			flags->minus = 1;
		else if (str[i] == '0')
			flags->zero = 1;
		i++;
	}
	if (flags->zero == 1 && flags->minus == 1)
		flags->zero = 0;
	return (i);
}

int		ft_check_width(t_flags *flags, char *str, va_list arg)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		i++;
		flags->star = 1;
		flags->width = va_arg(arg, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = flags->width * (-1);
			flags->zero = 0;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
		flags->width = flags->width * 10 + str[i++] - '0';
	return (i);
}

int		ft_check_precision(t_flags *flags, char *str, va_list arg)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
		{
			i++;
			flags->star = 1;
			flags->precision = va_arg(arg, int);
		}
		else
		{
			flags->precision = 0;
			while (str[i] >= '0' && str[i] <= '9')
				flags->precision = flags->precision * 10 + str[i++] - '0';
		}
	}
	return (i);
}

t_flags	ft_check_added_flags(t_flags *flags)
{
	if (flags->precision < 0)
		flags->precision = -1;
	if (flags->zero == 1 && flags->precision > -1
	&& ft_strchr("diuxX", flags->c) != 0)
		flags->zero = 0;
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = flags->width * -1;
	}
	return (*flags);
}

t_flags	ft_parser(t_flags *flags, const char *str, va_list arg)
{
	int		i;
	char	c;

	i = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->type = 0;
	flags->width = 0;
	flags->star = 0;
	flags->precision = -1;
	flags->c = '0';
	if (ft_strchr("cspdiuxX%", str[i]) == 0)
	{
		i += ft_zero_minus((char*)&str[i], flags);
		i += ft_check_width(flags, (char*)&str[i], arg);
		i += ft_check_precision(flags, (char*)&str[i], arg);
	}
	if ((c = ft_strchr("cspdiuxX%", str[i])) != '0')
		flags->c = c;
	ft_check_added_flags(flags);
	return (*flags);
}
