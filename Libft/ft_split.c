/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:27:11 by siseo             #+#    #+#             */
/*   Updated: 2022/04/03 17:48:14 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_num(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			num++;
		while (*s && *s != c)
			s++;
	}
	return (num);
}

static int	get_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	null_guard(char **result, int idx)
{
	int	i;

	if (result[idx])
		return (1);
	i = 0;
	while (i < idx)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	int		i;
	int		j;
	char	**result;

	if (!s)
		return (0);
	word_num = get_word_num(s, c);
	result = malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < word_num)
	{
		while (*s && *s == c)
			s++;
		result[i] = malloc(sizeof(char) * (get_word_len(s, c) + 1));
		if (!null_guard(result, i))
			return (0);
		j = 0;
		while (*s && *s != c)
			result[i][j++] = *(s++);
	}
	result[i] = 0;
	return (result);
}
