/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:19 by siseo             #+#    #+#             */
/*   Updated: 2022/06/25 23:53:30 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_len, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0 && dst_len < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + dstsize - dst_len - 1);
	}
	return (dstsize + dstsize - dst_len - 1);
}

char	*ft_strjoin(char *s1, char *s2, size_t s2_size, size_t *b_len)
{
	size_t	s1_size;
	char	*result;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	s1_size = ft_strlen(s1);
	result = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!result)
		return (0);
	result[0] = '\0';
	ft_strlcat(result, s1, 0, s1_size + 1);
	ft_strlcat(result, s2, s1_size, s1_size + s2_size + 1);
	free(s1);
	*b_len = s1_size + s2_size + 1;
	return (result);
}

size_t	ft_strlcpy(char **dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (*src == '\0')
	{
		free(*dst);
		*dst = 0;
		return (0);
	}
	else if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			(*dst)[i] = src[i];
			i++;
		}
		(*dst)[i] = '\0';
	}
	return (dstsize - 1);
}

int	check_new_line(char **backup, char **line, int size, size_t b_len)
{
	int		i;

	if (line && *line)
		free(*line);
	if (!*backup)
		return (0);
	if (b_len == 0)
		b_len = ft_strlen(*backup);
	*line = malloc(sizeof(char) * (b_len + 1));
	i = -1;
	while ((*backup)[++i] != '\0' && (i == 0 || (*backup)[i - 1] != '\n'))
		(*line)[i] = (*backup)[i];
	(*line)[i] = '\0';
	if ((*backup)[i - 1] == '\n')
	{
		ft_strlcpy(backup, &((*backup)[i]), b_len - (i - 1) + 1);
		return (1);
	}
	else if (size == 0 && (*backup)[i] == '\0')
	{
		free(*backup);
		*backup = 0;
	}
	return (0);
}
