/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:55:38 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/06 09:56:53 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_symbol(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	min;
	int	sum;

	i = 0;
	min = 1;
	sum = 0;
	while (is_space(str[i]))
		i++;
	while (is_symbol(str[i]))
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (is_number(str[i]))
	{
		sum = sum * 10 + (str[i] - '0') * min;
		i++;
	}
	return (sum);
}
