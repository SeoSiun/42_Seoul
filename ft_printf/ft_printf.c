/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:07:47 by siseo             #+#    #+#             */
/*   Updated: 2022/08/19 23:46:50 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fp	*init_fp(void)
{
	t_fp	*fp;

	fp = malloc(sizeof(t_fp) * 121);
	fp['c'] = print_c;
	fp['s'] = print_s;
	fp['p'] = print_pxx;
	fp['d'] = print_diu;
	fp['i'] = print_diu;
	fp['u'] = print_diu;
	fp['x'] = print_pxx;
	fp['X'] = print_pxx;
	fp['%'] = print_percent;
	return (fp);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	ap;
	t_fp	*fp;

	va_start(ap, s);
	result = 0;
	fp = init_fp();
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 0)
				break ;
			result += fp[(int)*s](*s, ap);
		}
		else
			result += write(1, s, 1);
		s++;
	}
	free(fp);
	va_end(ap);
	return (result);
}
