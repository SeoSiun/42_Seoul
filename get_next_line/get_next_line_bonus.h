/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:18:17 by siseo             #+#    #+#             */
/*   Updated: 2022/06/26 17:08:40 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char	*free_backup(t_backup *backup, int fd);

#endif