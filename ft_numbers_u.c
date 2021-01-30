/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:31:14 by paminna           #+#    #+#             */
/*   Updated: 2021/01/30 19:33:29 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		n_len_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*res;
	int		len;

	len = n_len_u(n);
	res = (char*)malloc(len + 1);
	if (res == 0)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

void	ft_process_u(t_flags *flags, va_list arg)
{
	int		i;
	char	*s;
	int		size;

	s = ft_itoa_u(va_arg(arg, unsigned int));
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
