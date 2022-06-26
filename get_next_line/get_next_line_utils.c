/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:19 by siseo             #+#    #+#             */
/*   Updated: 2022/06/26 17:07:53 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *s)
{
	int	i;

	i = 0;
	while (*s != '\n')
	{
		if (*s == '\0')
			return (-1);
		i++;
		s++;
	}
	return (i + 1);
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

char	*ft_strjoin(t_backup *backup, char *s2, size_t s2_size)
{
	char	*result;

	if (!backup->s)
	{
		backup->s = malloc(sizeof(char));
		backup->s[0] = '\0';
	}
	result = malloc(sizeof(char) * (backup->len + s2_size + 1));
	if (!result)
		return (0);
	result[0] = '\0';
	ft_strlcat(result, backup->s, 0, backup->len + 1);
	ft_strlcat(result, s2, backup->len, backup->len + s2_size + 1);
	free(backup->s);
	backup->len = backup->len + s2_size;
	return (result);
}

size_t	ft_strlcpy(t_backup *backup, const char *src, size_t dstsize)
{
	size_t	i;

	if (*src == '\0')
	{
		free_backup(backup, 0);
		return (0);
	}
	else if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			backup->s[i] = src[i];
			i++;
		}
		backup->s[i] = '\0';
		backup->len = i;
	}
	return (dstsize - 1);
}

int	check_new_line(t_backup *backup, char **line, int size)
{
	int		i;
	int		index;

	if (line && *line)
		free(*line);
	if (!backup->s)
		return (0);
	index = find_newline(backup->s);
	if (size != 0 && index == -1)
		return (0);
	*line = malloc(sizeof(char) * (backup->len + 1));
	i = -1;
	while (backup->s[++i] != '\0' && (i == 0 || backup->s[i - 1] != '\n'))
		(*line)[i] = backup->s[i];
	(*line)[i] = '\0';
	if (i != 0 && backup->s[i - 1] == '\n')
	{
		ft_strlcpy(backup, &(backup->s[i]), backup->len - (i - 1) + 1);
		return (1);
	}
	else if (size == 0 && backup->s[i] == '\0')
		free_backup(backup, 0);
	return (0);
}
