#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (*lst)
		ft_lstdelone(ft_lstlast(*lst), del);
	lst = 0;
}