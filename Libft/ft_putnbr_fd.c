#include "libft.h"

void	ft_putchar_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}