/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:25:39 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/22 15:09:40 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char a);

void	print_line(char start, char mid, char last, int cnt)
{
	ft_putchar(start);
	while (--cnt > 1)
		ft_putchar(mid);
	if (cnt)
		ft_putchar(last);
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y > 0 && x > 0)
	{
		while (i < y)
		{
			if (i == 0)
				print_line('/', '*', '\\', x);
			else if (i == y - 1)
				print_line('\\', '*', '/', x);
			else
				print_line('*', ' ', '*', x);
			write(1, "\n", 1);
			i++;
		}
	}
}
