/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:56:13 by siseo             #+#    #+#             */
/*   Updated: 2022/04/22 20:38:08 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count && SIZE_MAX / count < size)
		return (0);
	result = malloc(count * size);
	if (!result)
		return (0);
	ft_bzero(result, count * size);
	return (result);
}
