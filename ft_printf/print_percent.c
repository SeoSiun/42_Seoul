/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:32:13 by siseo             #+#    #+#             */
/*   Updated: 2022/08/19 23:50:27 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(char type, va_list ap)
{
	char	c;

	if (type != '%' && ap)
		return (0);
	c = '%';
	write(1, &c, 1);
	return (1);
}
