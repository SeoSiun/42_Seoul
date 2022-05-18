/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:19 by siseo             #+#    #+#             */
/*   Updated: 2022/05/18 17:00:43 by siseo            ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	i = 0;
	if (dstsize != 0 && dest_len < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - dest_len - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
		return (dest_len + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*result;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[0] = '\0';
	ft_strlcat(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (result);
}

size_t	ft_strlcpy(char **dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 1)
	{
		free(*dst);
		*dst = 0;
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
	return (ft_strlen(src));
}

int	check_new_line(char **back_up, char **line, int size)
{
	int		i;

	if (*line)
		free(*line);
	if (size == 0 && !*back_up)
		return (0);
	*line = malloc(sizeof(char) * (ft_strlen(*back_up) + 1));
	i = -1;
	while ((*back_up)[++i] != '\0' && (*back_up)[i - 1] != '\n')
		(*line)[i] = (*back_up)[i];
	(*line)[i] = '\0';
	if (size == 0)
	{
		free(*back_up);
		*back_up = 0;
	}
	else if ((*back_up)[i - 1] == '\n')
	{
		ft_strlcpy(back_up, &((*back_up)[i]), ft_strlen(&((*back_up)[i])) + 1);
		return (1);
	}
	return (0);
}
