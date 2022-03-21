/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:37:07 by siseo             #+#    #+#             */
/*   Updated: 2022/03/21 17:16:31 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_exist(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		i;
	char	*result;

	while (is_exist(*s1, set))
		s1++;
	size = 0;
	while (!is_exist(s1[size], set))
		size++;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (0);
}
