/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:27:53 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 20:38:34 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		n_len_base(unsigned long int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len = 1;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned int n, unsigned int base)
{
	char			*res;
	int				len;

	len = n_len_base(n);
	res = (char*)malloc(len + 1);
	if (res == 0)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len--] = "0123456789abcdef"[n % base];
		n /= base;
	}
	return (res);
}

void	ft_process_x(t_flags *flags, va_list arg)
{
	int		i;
	char	*s;
	int		size;

	s = ft_itoa_base(va_arg(arg, unsigned int), 16);
	i = 0;
	size = ft_strlen(s);
	if (flags->minus == 1)
		ft_minus_help(flags, s, &i, size);
	if (flags->minus == 0)
		ft_positive_help(flags, s, &i, size);
	while (s[i] != '\0')
		ft_putchar(flags, s[i++]);
	free(s);
}
