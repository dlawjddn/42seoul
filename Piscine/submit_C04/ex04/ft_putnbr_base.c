/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:17:52 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/30 17:01:30 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen3(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	dis_able(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = 0;
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (j < i)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	change(int nbr, char *base, int size)
{
	int	num;

	if (nbr == 0)
		return ;
	num = nbr % size;
	change(nbr / size, base, size);
	write(1, &base[num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	num;

	if (dis_able(base))
		return ;
	size = ft_strlen3(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = -(nbr % size);
		change(-(nbr / size), base, size);
		write(1, &base[num], 1);
	}
	else
	{
		num = nbr % size;
		change(nbr / size, base, size);
		write(1, &base[num], 1);
	}
}
