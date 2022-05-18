/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:13 by siseo             #+#    #+#             */
/*   Updated: 2022/05/18 16:43:46 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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

// void	test(int fd, char *filename) {
// 	int		cnt;
// 	char	*line;

// 	cnt = 0;
// 	printf("%s start\n", filename);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%d: %s\n", cnt++, line);
// 	}
// 	printf("%s end\n", filename);
// }

// int	main(void)
// {
// 	int		fd;

// 	fd = open("gnlTester/files/empty", O_RDWR);
// 	test(fd, "empty");
// 	fd = open("gnlTester/files/nl", O_RDWR);
// 	test(fd, "nl");
// 	fd = open("gnlTester/files/41_no_nl", O_RDWR);
// 	test(fd, "41_no_nl");
// 	fd = open("gnlTester/files/41_with_nl", O_RDWR);
// 	test(fd, "41_with_nl");
// 	fd = open("gnlTester/files/42_no_nl", O_RDWR);
// 	test(fd, "42_no_nl");
// 	fd = open("gnlTester/files/42_with_nl", O_RDWR);
// 	test(fd, "42_with_nl");
// fd = open("gnlTester/files/43_no_nl", O_RDWR);
// 	test(fd, "43_no_nl");
// 	fd = open("gnlTester/files/43_with_nl", O_RDWR);
// 	test(fd, "43_with_nl");
// }
