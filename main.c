/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:23:26 by paminna           #+#    #+#             */
/*   Updated: 2021/01/28 23:32:47 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("my : %d numb\n", 12);
	printf("my : %d numb\n", 12);
	// printf("orig minus : %-6.6d numb\n", 13);
	// ft_printf("  my minus : %-6.6d numb\n", 13);
	// printf("orig minus : %-2.2d numb\n", 13);
	// ft_printf("  my minus : %-2.2d numb\n", 13);
	// printf("orig : %3.3d numb\n", 13);
	// ft_printf("  my : %3.3d numb\n", 13);
	// printf("orig : %2.5d numb\n", 13);
	// ft_printf("  my : %2.5d numb\n", 13);
	// printf("orig : %6.3d numb\n", 13);
	// ft_printf("  my : %6.3d numb\n", 13);
}