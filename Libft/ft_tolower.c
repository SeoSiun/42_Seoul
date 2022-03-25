/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:02:53 by siseo             #+#    #+#             */
/*   Updated: 2022/03/25 15:32:57 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int	offset;

	offset = 'a' - 'A';
	if (c >= 'A' && c <= 'Z')
		return (c + offset);
	return (c);
}
