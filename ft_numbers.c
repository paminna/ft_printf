/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@stud.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:16:58 by paminna           #+#    #+#             */
/*   Updated: 2021/01/28 00:31:49 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_reverse_string(char *s, int index)
{
	int i;
	int h;
	
	i = 0;
	while (i >= 1)
	{
		s[index++] = i % 10 + '0';
		i /= 10;
	}
	while(i < index / 2)
	{
		h = s[index];
		s[index] = s[i];
		s[i] = h;
		i++;
		index--;
	}
	return (s);
}

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

void ft_process_int_help_3(t_flags *flags, char *s, int i, int size)
{
	if (flags->width != 0)
	{
		while (flags->width - 1 >= 0)
		{
			write(1, 0, 1);
			// while (flags->precision != size)
			// {
			// 	ft_putchar(flags, '0');
			// 	flags->precision--;
			// }
			// while (s[i] != '\0')
			// {
			// 	ft_putchar(flags, s[i]);
			// 	flags->width--;
			// 	i++;
			// }
			// ft_putchar(flags, ' ');
			// flags->width--;
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
	int index;
	int size;

	s = (char*)malloc(sizeof(char*));
	if (s == NULL)
		return;
	index = 0;
	i = va_arg(arg, int);
	while (i > 0)
	{
		s[index++] = i % 10 + '0';
		i /= 10;
	}
	s = ft_reverse_string(s, index - 1);
	i = 0;
	if (flags->minus == 1)
		ft_process_int_help(flags, s, i);
	else
		ft_process_int_help_2(flags, s, i);
	size = ft_strlen(s);
	if ( flags->precision != 0)
	{
		if (flags->minus == 1)
		{
			if (flags->precision <= size)
				ft_process_int_help(flags, s, i);
			else
				ft_process_int_help_3(flags, s, i, size);
		}
	}
	// ft_putchar(flags,s[index]);
	free(s);
}