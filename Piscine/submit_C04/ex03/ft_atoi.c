/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:14:38 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/29 13:22:22 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char a)
{
	if (a == '\t' || a == '\n' || a == ' ')
		return (1);
	else if (a == '\v' || a == '\f' || a == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	ans;
	int	i;

	i = 0;
	sign = 1;
	ans = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ans = ans * 10 + (str[i++] - '0');
		else
			return (ans * sign);
	}
	return (ans * sign);
}
