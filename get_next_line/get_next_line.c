/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:13 by siseo             #+#    #+#             */
/*   Updated: 2022/05/15 16:48:42 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*back_up[OPEN_MAX];
	char		*line;
	int			size;

	line = 0;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			break ;
		buf[size] = '\0';
		back_up[fd] = ft_strjoin(back_up[fd], buf);
		if (!back_up[fd])
			return (0);
		if (check_new_line(back_up[fd], line))
			return (line);
	}
	return (back_up[fd]);
}
