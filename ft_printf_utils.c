/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:55:14 by paminna           #+#    #+#             */
/*   Updated: 2021/01/28 20:11:26 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s[i]);
		i++;
	}
	if (s[i] == c)
		return (s[i]);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void ft_putchar(t_flags *flags, char sym)
{
	write(1, &sym, 1);
	flags->len++;
}

int		n_len(int n)
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

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	nbr;

	nbr = n;
	len = n_len(n);
	res = (char*)malloc(len + 1);
	if (res == 0)
		return (NULL);
	res[len--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		nbr = n * -1;
	}
	if (n == 0)
		res[0] = '0';
	while (nbr != 0)
	{
		res[len--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (res);
}