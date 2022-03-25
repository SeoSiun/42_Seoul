/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:06:57 by siseo             #+#    #+#             */
/*   Updated: 2022/03/25 15:31:31 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	if (!s)
		return (0);
	tmp = s;
	while (*s)
		s++;
	while (s >= tmp)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}
