/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:07:12 by paminna           #+#    #+#             */
/*   Updated: 2021/01/29 00:17:59 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_flags
{
	int minus;
	int zero;
	int width;
	int type;
	int precision;
	int star;
	char c;
	int len;
}				t_flags;

int 	ft_printf(const char *format, ...);
char	ft_strchr(const char *s, int c);
t_flags	ft_parser(t_flags *flags, const char *str, va_list arg);
t_flags ft_initialize(t_flags  *flags);
t_flags ft_check_added_flags(t_flags *flags);
int 	ft_check_width(t_flags *flags, char *str, va_list arg);
int 	ft_check_precision(t_flags *flags, char *str, va_list arg);
int 	ft_zero_minus(char *str, t_flags *flags);
int		ft_strlen(const char *s);
void 	ft_putchar(t_flags *flags, char sym);
void 	ft_process_char(t_flags *flags, va_list arg);
void 	ft_process_string(t_flags *flags, va_list arg);
void	ft_process_int(t_flags *flags, va_list arg);
void 	ft_process(t_flags *flags, va_list arg);
char 	*ft_reverse_string(char *s, int index);
void 	ft_process_int(t_flags *flags, va_list arg);
void 	ft_process_int_help(t_flags *flags, char *s, int i);
void 	ft_process_int_help_2(t_flags *flags, char *s, int i);
int		n_len(int n);
char	*ft_itoa(int n);

#endif 