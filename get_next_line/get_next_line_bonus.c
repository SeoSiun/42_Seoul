/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:13 by siseo             #+#    #+#             */
/*   Updated: 2022/06/26 17:09:00 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_backup(t_backup *backup, int fd)
{
	if ((fd >= 0 && fd < OPEN_MAX) && backup->s)
	{
		free(backup->s);
		backup->s = 0;
		backup->len = 0;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static t_backup	backup[OPEN_MAX];
	char			*line;
	int				size;

	line = 0;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (free_backup(&backup[fd], fd));
		if (size == 0)
		{
			check_new_line(&backup[fd], &line, size);
			return (line);
		}
		buf[size] = '\0';
		backup[fd].s = ft_strjoin(&backup[fd], buf, size);
		if (!backup[fd].s)
			return (0);
		if (check_new_line(&backup[fd], &line, size))
			return (line);
	}
}
