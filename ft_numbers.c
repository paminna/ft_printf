/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:16:58 by paminna           #+#    #+#             */
/*   Updated: 2021/01/29 00:36:25 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_process_int_help_2(t_flags *flags, char *s, int i)
{
	if (flags->width != 0)
	{
		while (flags->width != 0)
		{
			while (flags->width - 1 - ft_strlen(s) >= 0)
			{
				ft_putchar(flags, ' ');
				flags->width--;
			}
			ft_putchar(flags, s[i++]);
			flags->width--;
		}
	}
	else
	{
		while (s[i] != '\0')
			ft_putchar(flags, s[i++]);
	}
}

void ft_process_int_help(t_flags *flags, char *s, int i)
{
	if (flags->width != 0)
	{
		while (flags->width - 1 >= 0)
		{
			while (s[i] != '\0')
			{
				ft_putchar(flags, s[i]);
				flags->width--;
				i++;
			}
			ft_putchar(flags, ' ');
			flags->width--;
		}
	}
	else
	{
		while (s[i] != '\0')
			ft_putchar(flags, s[i++]);
	}
}


void ft_process_int(t_flags *flags, va_list arg)
{
	int i;
	char *s;
	int size;

	s = ft_itoa(va_arg(arg, int));
	size = ft_strlen(s);
	i = 0;
	if (flags->minus == 1)
	{
		if (flags->precision > size)
		{
			while (flags->precision-- - size != 0)
				ft_putchar(flags, '0');
			while (flags->width-- - 1 > flags->precision)
				ft_putchar(flags, s[i++]);
		} 
		else {
			while (flags->width - size > 0 && s[i] != 0)
				ft_putchar(flags, s[i++]);
			while (flags->width - size > 0)
			{
				ft_putchar(flags, ' ');
				flags->width--;
			}
		}
	}
	if (flags->minus == 0)
	{
		printf("%d", flags->zero);
		if (flags->zero == 1)
		{
			while (flags->width-- != 0)
				ft_putchar(flags, '0');
		}
		if (flags->precision - size > 0)
		{
			while (flags->width-- - 1 > flags->precision)
				ft_putchar(flags, ' ');
			if (s[i] == '-')
			{	
				ft_putchar(flags, s[i++]);
				size--;
			}
			while (flags->precision-- - size > 0)
				ft_putchar(flags, '0');
			while (flags->precision-- - size > 0)
				ft_putchar(flags, '0');
		}
		else
			while (flags->width-- - size > 0)
				ft_putchar(flags, ' ');
	}
	
	while (s[i] != '\0')
		ft_putchar(flags, s[i++]);
	// while (s[i] != '\0')
	// 	ft_putchar(flags, s[i++]);
	// if (flags->minus == 1 && flags->precision == 0)
	// 	ft_process_int_help(flags, s, i);
	// else if (flags->minus == 0 && flags->precision == 0)
	// 	ft_process_int_help_2(flags, s, i);
	// size = ft_strlen(s);
	// if ( flags->precision != 0)
	// {
	// 	if (flags->minus == 1 && flags->width != 0)
	// 	{
	// 		if (flags->precision > size)
	// 		{
	// 			while (flags->precision != size)
	// 			{
	// 				ft_putchar(flags, '0');
	// 				flags->precision--;
	// 			}
	// 		}
	// 		while (flags->width - flags->precision >= 0)
	// 		{
	// 			while (s[i] != '\0')
	// 			{
	// 				ft_putchar(flags, s[i]);
	// 				flags->width--;
	// 				i++;
	// 			}
	// 		ft_putchar(flags, ' ');
	// 		flags->width--;
	// 		}
	// 	}
	// 	if (flags->minus == 0 && flags->width != 0)
	// 	{
	// 		if (flags->precision <= size)
	// 		{
	// 			while (flags->width - size != 0)
	// 			{
	// 				ft_putchar(flags, ' ');
	// 				flags->width--;
	// 			}
	// 		}
	// 		else if (flags->precision > size)
	// 		{
	// 			while (flags->width - size - flags->precision != 0)
	// 			{
	// 				ft_putchar(flags, ' ');
	// 				flags->width--;
	// 			}
	// 			while (flags->precision != size)
	// 			{
	// 				ft_putchar(flags, '0');
	// 				flags->precision--;
	// 			}
	// 		}
	// 		while (s[i] != '\0')
	// 		{
	// 			ft_putchar(flags, s[i]);
	// 			flags->width--;
	// 			i++;
	// 		}

	// 	}
	// }
	// ft_putchar(flags,s[index]);
	free(s);
}