/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:33:16 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/09 11:23:43 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	add(int *size, char **s)
{
	int		i;
	char	*temp;
	int		new;

	i = 0;
	new = *size + 1;
	temp = (char *)malloc(sizeof(char) * new);
	if (!temp)
		return ;
	while (i < *size)
	{
		temp[i] = (*s)[i];
		i++;
	}
	*size = *size + 1;
	temp[i] = 0;
	free(*s);
	*s = temp;
}

int	same_check(char c, char *sign, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sign[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*read_one(int fd, char *sign)
{
	char	*set;
	char	c;
	int		size;

	set = (char *)malloc(sizeof(char));
	if (!set)
		return (0);
	c = 0;
	size = 1;
	while (c != '\n')
	{
		read(fd, &c, 1);
		if (c != '\n')
		{
			if (!same_check(c, sign, 2))
				return (0);
			set[size - 1] = c;
			add(&size, &set);
		}
	}
	if (size == 1)
		return (0);
	return (set);
}

char	*read_all(int fd, int len, char *sign)
{
	char	*set;
	char	c;
	int		i;

	set = (char *)malloc(sizeof(char) * (len + 1));
	if (!set)
		return (0);
	if (read(fd, set, len) != len)
		return (0);
	set[len] = 0;
	i = -1;
	while (set[++i])
	{
		if (!same_check(set[i], sign, 2))
			return (0);
	}
	read(fd, &c, 1);
	if (c != '\n')
		return (0);
	return (set);
}

char	**make_map(int fd, int sum, char *sign)
{
	char	**map;
	char	c;
	int		i;
	int		len;

	map = (char **)malloc(sizeof(char *) * (sum + 1));
	if (!map)
		return (0);
	i = 0;
	len = 0;
	map[i] = read_one(fd, sign);
	if (!map[i])
		return (0);
	while (map[i][len])
		len++;
	while (++i < sum)
	{
		map[i] = read_all(fd, len, sign);
		if (!map[i])
			return (0);
	}
	if (read(fd, &c, 1) != 0)
		return (0);
	map[i] = 0;
	return (map);
}
