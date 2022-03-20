/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:59:34 by siseo             #+#    #+#             */
/*   Updated: 2022/03/15 17:59:34 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	i = 0;
	if (dstsize != 0 && dest_len < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - dest_len - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
		return (dest_len + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}