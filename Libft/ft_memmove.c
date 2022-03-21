/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:18:13 by siseo             #+#    #+#             */
/*   Updated: 2022/03/21 17:03:38 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if ((size_t)(dst - src) >= len)
		ft_memcpy(dst, src, len);
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			((unsigned char *)(dst))[i] = ((const unsigned char *)(src))[i];
			i--;
		}
	}
	return (dst);
}
