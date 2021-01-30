/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bigx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:01:50 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 19:32:18 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_bigx(unsigned int n, unsigned int base)
{
	char	*res;
	int		len;

	len = n_len_base(n);
	res = (char*)malloc(len + 1);
	if (res == 0)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len--] = "0123456789ABCDEF"[n % base];
		n /= base;
	}
	return (res);
}

void	ft_process_bigx(t_flags *flags, va_list arg)
{
	int		i;
	char	*s;
	int		size;

	s = ft_itoa_base_bigx(va_arg(arg, unsigned int), 16);
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
