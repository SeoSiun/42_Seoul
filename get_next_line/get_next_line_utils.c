/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:19 by siseo             #+#    #+#             */
/*   Updated: 2022/05/15 17:03:36 by siseo            ###   ########.fr       */
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (0);
	if ((size_t)(dst - src) >= len)
	{	
		i = 0;
		while (i < (int)len)
		{
			((unsigned char *)(dst))[i] = ((const unsigned char *)(src))[i];
			i++;
		}
	}
	else
	{
		i = (int)(len - 1);
		while (i >= 0)
		{	
			((unsigned char *)(dst))[i] = ((const unsigned char *)(src))[i];
			i--;
		}
	}
	return (dst);
}

int	check_new_line(char *back_up, char *line)
{
	int		i;

	if (line)
		free(line);
	line = malloc(sizeof(char) * (ft_strlen(back_up) + 1));
	i = 0;
	while (back_up[i] != '\0' && back_up[i] != '\n')
	{
		line[i] = back_up[i];
		i++;
	}
	line[i] = '\0';
	if (back_up[i] == '\n')
	{
		i++;
		ft_memmove(back_up, &back_up[i], ft_strlen(&back_up[i]));
		return (1);
	}	
	return (0);
}
