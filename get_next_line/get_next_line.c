/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:13 by siseo             #+#    #+#             */
/*   Updated: 2022/06/26 00:09:52 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	char		*line;
	int			size;
	size_t		b_len;

	line = 0;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (free_backup(&backup[fd]));
		if (size == 0)
		{
			check_new_line(&backup[fd], &line, size, 0);
			return (line);
		}
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf, size, &b_len);
		if (!backup[fd])
			return (0);
		if (check_new_line(&backup[fd], &line, size, b_len))
			return (line);
	}
}

char	*free_backup(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = 0;
	}
	return (0);
}
