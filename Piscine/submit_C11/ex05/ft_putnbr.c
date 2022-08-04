/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:06:23 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/06 10:19:12 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_printnbr(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	c = '0' + nb % 10;
	ft_printnbr(nb / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	a;

	if (nb < 0)
	{
		write(1, "-", 1);
		a = '0' - nb % 10;
		ft_printnbr(-(nb / 10));
	}
	else
	{
		a = '0' + nb % 10;
		ft_printnbr(nb / 10);
	}
	write(1, &a, 1);
}
