/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:07:12 by paminna           #+#    #+#             */
/*   Updated: 2021/01/12 01:32:52 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_flags
{
	int minus;
	int zero;
	int width;
	int type;
	int precision;
	int star_width;
	int star;
	int space;
	int sharp;
	int plus;
	char c;
}				t_flags;

int ft_parser(const char *str, t_flags *flags, int len, va_list arg);
int ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
t_flags ft_parse_flags(t_flags *flags, const char *str, int *len, va_list arg);
t_flags ft_initialize(t_flags  *flags);
int	ft_strlen(const char *s);

#endif 