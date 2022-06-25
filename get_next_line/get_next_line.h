/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:17 by siseo             #+#    #+#             */
/*   Updated: 2022/06/26 00:46:50 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_backup
{
	char	*s;
	size_t	len;
}	t_backup;

char	*get_next_line(int fd);
char	*ft_strjoin(t_backup *backup, char *s2, size_t s2_size);
int		check_new_line(t_backup *backup, char **line, int size);
char	*free_backup(t_backup *backup);

#endif