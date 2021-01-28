/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@stud.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:52:51 by paminna           #+#    #+#             */
/*   Updated: 2021/01/27 22:46:14 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_process(t_flags *flags, va_list arg)
{
	if (flags->c == 'c')
		ft_process_char(flags, arg);
	if (flags->c == 's')
		ft_process_string(flags, arg);
	if (flags->c == 'd')
		ft_process_int(flags, arg);
}