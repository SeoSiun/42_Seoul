
#include "libft.h"

int	get_word_num(char const *s, char c)
{
	int	num;
	
	num = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			num++;
		while (*s && *s != c)
			s++;
	}
	return (num);
}

int	get_word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

void	free_all(char **result, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	int		word_len;
	int		i;
	char	**result;

	word_num = get_word_num(s, c);
	result = malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (0);
	while (i < word_num)
	{
		while(*s && *s == c)
			s++;
		word_len = get_word_len(s, c);
		result[i] = malloc(sizeof(char) * (word_len + 1));
		if (!(result[i]))
		{
			free_all(result, i);
			return (0);
		}
		while (*s && *s != c)
		{
			*(result[i]) = *s;
			(result[i])++;
			s++;
		}
	}
	result[i] = 0;
	return (0);
}