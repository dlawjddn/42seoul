/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:41:09 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/06 22:34:52 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "print_map.h"

void	change_map(t_location max, char fill_map, char **map)
{
	int	start_x;
	int	start_y;
	int	temp;

	start_x = max.x - max.square + 1;
	start_y = max.y - max.square + 1;
	temp = start_x;
	while (start_y <= max.y)
	{
		start_x = temp;
		while (start_x <= max.x)
		{
			map[start_y][start_x] = fill_map;
			start_x++;
		}
		start_y++;
	}
}

int	**find_first_line(t_location map_size, char **map, char empty)
{
	int	i;
	int	**dp;
	int	limit;

	i = -1;
	limit = find_max(map_size.y, map_size.x);
	dp = set_int_map(map_size);
	if (!dp)
		return (0);
	i = -1;
	while (++i < limit)
	{
		if (i < map_size.y && map[i][0] == empty)
			dp[i][0] = 1;
		else if (i < map_size.y && map[i][0] != empty)
			dp[i][0] = 0;
		if (i < map_size.x && map[0][i] == empty)
			dp[0][i] = 1;
		else if (i < map_size.x && map[0][i] != empty)
			dp[0][i] = 0;
	}
	return (dp);
}

t_location	use_dp(t_location map_size, int **dp, char **map, char disable)
{
	int			i;
	int			j;
	t_location	max;

	i = -1;
	max.square = 0;
	while (++i < map_size.y)
	{
		j = -1;
		while (++j < map_size.x)
		{
			if (map[i][j] == disable)
				dp[i][j] = 0;
			else if (i != 0 && j != 0)
				dp[i][j] = 1 + find_min(dp, i, j);
			if (max.square < dp[i][j])
			{
				max.square = dp[i][j];
				max.x = j;
				max.y = i;
			}
		}
	}
	return (max);
}

int	find_max_square(char **map, int y_size, char *sign)
{
	int			**dp;
	int			i;
	t_location	max;
	t_location	map_size;

	map_size.x = 0;
	map_size.y = y_size;
	max.square = 0;
	while (map[0][map_size.x])
		map_size.x++;
	dp = find_first_line(map_size, map, sign[0]);
	if (!dp)
		return (0);
	max = use_dp(map_size, dp, map, sign[1]);
	change_map(max, sign[2], map);
	i = -1;
	while (++i < map_size.y)
		free(dp[i]);
	free(dp);
	return (1);
}

int	print_map(char **map, int size, char *sign)
{
	int	i;
	int	x_size;

	if (!find_max_square(map, size, sign))
		return (0);
	i = 0;
	x_size = 0;
	while (map[0][x_size])
		x_size++;
	while (i < size)
	{
		write(1, map[i], x_size);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}
