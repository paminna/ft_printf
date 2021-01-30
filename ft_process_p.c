/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:52:51 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 17:09:49 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_p(unsigned long int n, unsigned int base)
{
	char			*res;
	int				len;

	len = n_len_base((unsigned long int) n);
	res = (char*)malloc(len + 1);
	if (res == 0)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len--] = "0123456789abcdef"[n % base];
		n /= 16;
	}
	return (res);
}

void ft_minus_help_2_p(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	if (s[i] == '0')
		flags->width--;
	while (flags->precision-- - size > 0)
		ft_putchar(flags, '0');
	if (flags->width-- > flags->precision && s[i] != '\0')
	{
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');
		flags->width -= 2;
		while (flags->width-- > flags->precision && s[i] != '\0')
			ft_putchar(flags, s[i++]);
	}
	while (flags->width - 2 > 0)
	{
		ft_putchar(flags, ' ');
		flags->width--;
	}
	*c = i;
}

void ft_minus_help_p(t_flags *flags, char *s, int *i, int size)
{
	int c;

	c = *i;
	if (s[c] == '0' && flags->precision == 0)
		size = 1;
	if (flags->precision > size)
		ft_minus_help_2(flags, s, &c, size);
	else 
	{
		if (flags->width - size > 0 && s[c] != '\0')
		{
			ft_putchar(flags, '0');
			ft_putchar(flags, 'x');
			flags->width -= 2;
			while (flags->width - size > 0 && s[c] != '\0')
				ft_putchar(flags, s[c++]);
		}
		else 
		{
			ft_putchar(flags, '0');
			ft_putchar(flags, 'x');
			flags->width -= 2;
		}
		while (flags->width - size > 0)
		{
			ft_putchar(flags, ' ');
			flags->width--;
		}
	}
	*i = c;
}

void ft_positive_help_2_p(t_flags *flags, int *c, int size)
{
	int i;

	i = *c;
	if (flags->width > flags->precision)
	{
		while (flags->width--  > flags->precision - 2)
			ft_putchar(flags, ' ');
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');
	}
	if (flags->precision - size > 0)
	{
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');
		while (flags->precision-- - size > 0)
			ft_putchar(flags, '0');
	}	
	*c = i;
}

void ft_positive_help_p(t_flags *flags, char *s, int *i, int size)
{
	int c;

	c = *i;
	if (s[c] == '0' && flags->precision == 0)
	{
		size = 0;
		s[c] = '\0';
	}
	if (flags->precision - size > 0)
		ft_positive_help_2_p(flags, &c, size);
	else if (flags->zero == 1 && flags->width - size > 0)
	{
		if (flags->precision - size > 0)
		{
			ft_putchar(flags, '0');
			ft_putchar(flags, 'x');
			while (flags->precision-- - size > 0)
				ft_putchar(flags, '0');
		}	
	}
	else if (flags->width - size > 0)
	{
		while (flags->width-- - size - 2 > 0)
			ft_putchar(flags, ' ');
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');
	}
	else if (flags->width == 0 && flags->precision < 1)
	{
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');	
	}
	else if (flags->width != 0)
	{
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');	
	}
	*i = c;
}

void 	ft_process_p(t_flags *flags, va_list arg)
{
	int i;
	char *s;
	int size;

	s = ft_itoa_base_p(va_arg(arg, unsigned long int), 16);
	i = 0;
	size = ft_strlen(s);
	if (size == 0)
	{
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');
	}
	if (flags->minus == 1)
		ft_minus_help_p(flags, s, &i, size);
	if (flags->minus == 0)
		ft_positive_help_p(flags, s, &i, size);
	while (s[i] != '\0')
		ft_putchar(flags, s[i++]);
	free(s);
}
