/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:13 by siseo             #+#    #+#             */
/*   Updated: 2022/06/20 16:08:42 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			return (0);
		if (size == 0)
			break ;
		buf[size] = '\0';
		back_up[fd] = ft_strjoin(back_up[fd], buf);
		if (!back_up[fd])
			return (0);
		if (check_new_line(&back_up[fd], &line, size))
			return (line);
	}
	check_new_line(&back_up[fd], &line, size);
	return (line);
}
