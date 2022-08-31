/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:14:57 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 17:28:55 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_nbr(long long n)
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

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*res;
	int			len;

	len = count_nbr((long long)n);
	nbr = (long long)n;
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
