/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:56:09 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/29 10:59:53 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	num_write(long num)
{
	char	temp;

	if (num == 0)
		return ;
	else
	{
		num_write(num / 10);
		temp = num % 10 + '0';
		write(1, &temp, 1);
	}
}

void	ft_putnbr(int nb)
{
	long	num;

	num = nb;
	if (num < 0)
	{
		write(1, "-", 1);
		num_write(num * -1);
	}
	else
	{
		if (num == 0)
			write(1, "0", 1);
		else
			num_write(num);
	}
}
