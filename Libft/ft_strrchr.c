/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:06:57 by siseo             #+#    #+#             */
/*   Updated: 2022/03/16 17:12:37 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (*s)
		s++;
	while (s >= tmp)
	{
		if (*s == c)
			return (s);
		s--;
	}
	return (NULL);
}
