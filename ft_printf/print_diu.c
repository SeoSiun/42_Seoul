/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:32:20 by siseo             #+#    #+#             */
/*   Updated: 2022/08/20 00:03:55 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_decimal_len(long long decimal)
{
	int	len;

	len = 0;
	if (decimal <= 0)
	{
		decimal *= -1;
		len++;
	}
	while (decimal > 0)
	{
		len++;
		decimal /= 10;
	}
	return (len);
}

void	print_decimal(long long decimal)
{
	if (decimal < 0)
	{
		write(1, "-", 1);
		decimal *= -1;
	}
	if (decimal >= 10)
	{
		print_decimal(decimal / 10);
		print_decimal(decimal % 10);
	}
	else
		write(1, &("0123456789"[decimal]), 1);
}

int	print_diu(char type, va_list ap)
{
	long long	decimal;

	if (type == 'u')
		decimal = va_arg(ap, unsigned int);
	else
		decimal = va_arg(ap, int);
	print_decimal(decimal);
	return (get_decimal_len(decimal));
}
