/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:48:04 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/06 22:32:32 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

int	find_min(int **dp, int i, int j)
{
	int	a;
	int	b;
	int	c;
	int	n;

	a = dp[i][j - 1];
	b = dp[i - 1][j];
	c = dp[i - 1][j - 1];
	n = a;
	if (n > b)
		n = b;
	if (n > c)
		n = c;
	return (n);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	**set_int_map(t_location map_size)
{
	int	**set;
	int	i;

	set = (int **)malloc(sizeof(int *) * map_size.y);
	if (!set)
		return (0);
	i = -1;
	while (++i < map_size.y)
	{
		set[i] = (int *)malloc(sizeof(int) * map_size.x);
		if (!set)
			return (0);
	}
	return (set);
}
