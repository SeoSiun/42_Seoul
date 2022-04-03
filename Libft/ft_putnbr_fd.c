/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:26:47 by siseo             #+#    #+#             */
/*   Updated: 2022/04/03 16:16:13 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		string_num[10];
	int			i;
	long long	long_num;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	long_num = (long long)n;
	if (long_num < 0)
	{
		write(fd, "-", 1);
		long_num *= -1;
	}
	i = 0;
	while (long_num)
	{
		string_num[9 - i++] = long_num % 10 + '0';
		long_num /= 10;
	}
	write(fd, &string_num[9 - i + 1], i);
}
