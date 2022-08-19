/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:32:23 by siseo             #+#    #+#             */
/*   Updated: 2022/08/20 00:11:30 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define LOWER_CASE 0
#define UPPER_CASE 1

int	get_hex_len(unsigned long long hex)
{
	int	len;

	if (hex == 0)
		return (1);
	len = 0;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

void	print_hex(unsigned long long hex, int option)
{
	if (hex >= 16)
		print_hex(hex / 16, option);
	if (option == LOWER_CASE)
		write(1, &("0123456789abcdef"[hex % 16]), 1);
	else if (option == UPPER_CASE)
		write(1, &("0123456789ABCDEF"[hex % 16]), 1);
}

int	print_pxx(char type, va_list ap)
{
	unsigned long long	hex;
	int					len;

	len = 0;
	if (type == 'p')
	{
		hex = va_arg(ap, unsigned long long);
		len += write(1, "0x", 2);
	}
	else
		hex = va_arg(ap, unsigned int);
	if (type == 'p' || type == 'x')
		print_hex(hex, LOWER_CASE);
	else
		print_hex(hex, UPPER_CASE);
	return (len + get_hex_len(hex));
}
