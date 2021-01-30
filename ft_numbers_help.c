/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:50:47 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 20:00:47 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_positive_help_2(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	if (s[i] == '-')
		flags->width--;
	while (flags->width-- > flags->precision)
		ft_putchar(flags, ' ');
	if (s[i] == '-')
	{
		ft_putchar(flags, s[i++]);
		size--;
	}
	while (flags->precision-- - size > 0)
		ft_putchar(flags, '0');
	*c = i;
}

void	ft_minus_help_2(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	if (s[i] == '-')
	{
		ft_putchar(flags, s[i++]);
		size--;
		flags->width--;
	}
	while (flags->precision - size++ > 0)
		ft_putchar(flags, '0');
	while (flags->width > flags->precision && s[i] != '\0')
		ft_putchar(flags, s[i++]);
	while (flags->width-- - flags->precision > 0)
		ft_putchar(flags, ' ');
	*c = i;
}

void	ft_minus_help_3(t_flags *flags, char *s, int *c, int size)
{
	int i;

	i = *c;
	while (flags->width - size > 0 && s[i] != '\0')
		ft_putchar(flags, s[i++]);
	while (flags->width-- - size > 0)
		ft_putchar(flags, ' ');
	*c = i;
}
