/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:56:38 by siseo             #+#    #+#             */
/*   Updated: 2022/07/12 16:09:38 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef int	(*t_fp)(char type, va_list ap);

int	print_c(char type, va_list ap);
int	print_diu(char type, va_list ap);
int	print_percent(char type, va_list ap);
int	print_pxx(char type, va_list ap);
int	print_s(char type, va_list ap);

#endif