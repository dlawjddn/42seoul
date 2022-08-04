/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:23:59 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/28 22:44:21 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_sixteen(unsigned char a)
{
	a += '0';
	if (a > '9')
		a += 39;
	write(1, &a, 1);
}

void	change_sixteen(unsigned char c)
{
	write(1, "\\", 1);
	print_sixteen((int)c / 16);
	print_sixteen((int)c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 127 || str[i] < 32)
			change_sixteen(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
