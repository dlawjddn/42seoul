/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:38 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 17:26:39 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	count_ll(long long n)
{
	int	cnt_nbr;

	if (n == 0)
		return (1);
	cnt_nbr = 0;
	if (n < 0)
		cnt_nbr = 1;
	while (n)
	{
		n /= 10;
		cnt_nbr++;
	}
	return (cnt_nbr);
}

char	*ft_litoa(long long n)
{
	long long	nbr;
	char		*res;
	int			len;

	len = count_ll((long long)n);
	nbr = n;
	if (n < 0)
		nbr *= -1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
