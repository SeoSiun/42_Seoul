/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:12:53 by siseo             #+#    #+#             */
/*   Updated: 2022/03/25 17:36:34 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long long num)
{
	int	size;

	if (num == 0)
		return (1);
	size = 0;
	if (num < 0)
	{
		size++;
		num *= -1;
	}
	while (num)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			size;
	char		*result;

	num = n;
	size = get_size(num);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	result[size] = '\0';
	while ((size == 1 && result[0] != '-') || size > 1)
	{
		result[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
