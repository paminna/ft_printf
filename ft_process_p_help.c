/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:34:00 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 20:37:38 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_help_2_p(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	if (s[i] == '0')
		flags->width--;
	while (flags->precision - size++ > 0)
		ft_putchar(flags, '0');
	if (flags->width > flags->precision && s[i] != '\0')
	{
		ft_putchar(flags, '0');
		ft_putchar(flags, 'x');
		while (flags->width > flags->precision && s[i] != '\0')
			ft_putchar(flags, s[i++]);
	}
	while (flags->width - flags->precision > 0)
	{
		ft_putchar(flags, ' ');
		flags->width--;
	}
	*c = i;
}

void	ft_minus_help_p_2(t_flags *flags, char *s, int *i, int size)
{
	int c;

	c = *i;
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
	*i = c;
}

void	ft_minus_help_p(t_flags *flags, char *s, int *i, int size)
{
	int c;

	c = *i;
	if (s[c] == '0' && flags->precision == 0)
		size = 1;
	if (flags->precision >= size)
		ft_minus_help_2(flags, s, &c, size);
	else
		ft_minus_help_p_2(flags, s, &c, size);
	*i = c;
}

void	ft_positive_help_2_p(t_flags *flags, int *c, int size)
{
	int i;

	i = *c;
	if (flags->width > flags->precision)
	{
		while (flags->width-- > flags->precision - 2)
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
