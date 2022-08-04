/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:27:00 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/09 11:26:36 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

char	*set_first(int size, char *sign, int *sum)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * 4);
	if (!word)
		return (0);
	i = -1;
	while (++i < 4)
	{
		word[i] = sign[size - 4 + i];
		if (same_check(word[i], word, i) || (word[i] < 32 || word[i] > 126))
			if (i != 3)
				return (0);
		sign[size - 4 + i] = 0;
	}
	i = -1;
	*sum = 0;
	while (sign[++i])
	{
		if (sign[i] < '0' || sign[i] > '9')
			return (0);
		*sum = *sum * 10 + (sign[i] - '0');
	}
	free(sign);
	return (word);
}

char	*input_first(int fd, int *sum)
{
	char	*sign;
	char	*word;
	char	c;
	int		size;

	sign = (char *)malloc(sizeof(char));
	if (!sign)
		return (0);
	size = 1;
	c = 0;
	while (c != '\n')
	{
		if (!read(fd, &c, 1))
			return (0);
		if (c != '\n')
		{
			sign[size - 1] = c;
			add(&size, &sign);
		}
	}
	if (size < 5)
		return (0);
	word = set_first(size, sign, sum);
	return (word);
}

void	memory_free(char *sign, char **map)
{
	int	i;

	i = 0;
	free(sign);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

int	input_data(int fd)
{
	int			sum;
	char		*sign;
	char		**map;

	sign = input_first(fd, &sum);
	if (!sign || !sum)
		return (0);
	map = make_map(fd, sum, sign);
	if (!map)
		return (0);
	if (!print_map(map, sum, sign))
		return (0);
	memory_free(sign, map);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	fd = 0;
	if (argc < 2)
	{
		if (!input_data(fd))
			write(1, "map error\n", 10);
	}
	else if (argc >= 2)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1 || !input_data(fd))
				write(1, "map error\n", 10);
			close(fd);
			if (i != argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
