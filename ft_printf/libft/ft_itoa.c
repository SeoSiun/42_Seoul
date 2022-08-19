/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:12:53 by siseo             #+#    #+#             */
/*   Updated: 2022/04/23 15:15:36 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	long	num;

	size = get_size(n);
	num = n;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	if (num == 0)
		result[0] = '0';
	result[size--] = '\0';
	while (num)
	{
		result[size--] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
