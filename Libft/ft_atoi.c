/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:50:36 by siseo             #+#    #+#             */
/*   Updated: 2022/04/06 18:48:46 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	check_range(unsigned long long num, int sign)
{
	if (num > 9223372036854775807 && sign == 1)
		return (-1);
	else if (num >= 9223372036854775808u && sign == -1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	int					check;
	unsigned long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		check = check_range(num, sign);
		if (check != 1)
			return (check);
	}
	return (sign * num);
}
