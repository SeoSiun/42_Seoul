/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:30:40 by siseo             #+#    #+#             */
/*   Updated: 2022/03/21 16:14:08 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoint(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	ft_strlcat(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s2) + 1);
	return (result);
}