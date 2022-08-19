/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:12:18 by siseo             #+#    #+#             */
/*   Updated: 2022/04/06 18:58:45 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	size = 0;
	while (!(ft_strlen(s) < start) && s[start + size] && size < len)
		size++;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
