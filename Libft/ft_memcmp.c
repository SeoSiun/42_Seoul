/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:28:56 by siseo             #+#    #+#             */
/*   Updated: 2022/03/25 15:25:45 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*_s1;
	const unsigned char	*_s2;

	i = 0;
	_s1 = (const unsigned char *)s1;
	_s2 = (const unsigned char *)s2;
	while (_s1[i] != '\0' && _s2[i] != '\0' && _s1[i] == _s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (_s1[i] - _s2[i]);
}
