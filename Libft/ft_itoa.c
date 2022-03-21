#include "libft.h"

int	get_size(long long num)
{
	int	size;

	if (num == 0)
		return (1);
	size = 0;
	if (num < 0)
	{
		size++;
		num *= -1;
	}
	while (num)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			size;
	char		*result;

	num = n;
	size = get_size(num);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	if (num < 0)
	{
		*result = '-';
		num *= -1;
	}
	result[size] = '\0';
	while ((size == 0 && result[0] != '-') || size > 0)
	{
		result[--size] = num % 10;
		num /= 10;
	}
	return (result);
}
