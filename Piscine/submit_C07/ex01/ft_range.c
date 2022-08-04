/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:43:42 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/04 17:12:58 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	num;
	int	*arr;

	i = 0;
	num = min;
	if (min >= max)
		return (0);
	arr = (int *)malloc((max - min) * (sizeof(int)));
	while (num < max)
		arr[i++] = num++;
	return (arr);
}
