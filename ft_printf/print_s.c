/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:32:26 by siseo             #+#    #+#             */
/*   Updated: 2022/08/20 00:10:48 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char type, va_list ap)
{
	char	*s;
	int		len;

	if (type != 's')
		return (0);
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
