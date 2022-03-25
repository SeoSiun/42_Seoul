/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:37:07 by siseo             #+#    #+#             */
/*   Updated: 2022/03/25 20:45:22 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_exist(char c, char const *set)
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
	int		i;
	int		j;
	char	*result;

	while (s1 && is_exist(*s1, set))
		s1++;
	j = ft_strlen(s1);
	while (j > 0 && is_exist(s1[j - 1], set))
		j--;
	result = malloc(sizeof(char) * (j + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < j)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
