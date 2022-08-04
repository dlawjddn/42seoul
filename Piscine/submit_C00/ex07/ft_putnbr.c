/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:44:13 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/22 21:10:12 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_write(int nb)
{
	int		temp;
	char	num;

	if (nb == 0)
		return ;
	else
	{
		temp = nb / 10;
		ft_write(temp);
		temp = nb % 10;
		num = temp + '0';
		write(1, &num, 1);
	}
}

void	ft_putnbr(int nb)
{
	int		tmp;
	char	a;

	if (nb < 0)
	{
		write(1, "-", 1);
		tmp = nb % 10 * -1;
		nb = nb / 10 * -1;
		ft_write(nb);
		a = tmp + '0';
		write(1, &a, 1);
	}
	else
	{
		if (nb == 0)
			write(1, "0", 1);
		else
			ft_write(nb);
	}
}
