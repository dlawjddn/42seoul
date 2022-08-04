/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:38:40 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/05 16:10:58 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*num;

	i = 0;
	num = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		num[i] = f(tab[i]);
		i++;
	}
	return (num);
}
