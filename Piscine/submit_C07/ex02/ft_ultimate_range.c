/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:03:58 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/04 11:30:13 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*num;

	i = 0;
	num = (int *)malloc((max - min) * sizeof(int));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!num)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
		num[i++] = min++;
	*range = num;
	return (i);
}
