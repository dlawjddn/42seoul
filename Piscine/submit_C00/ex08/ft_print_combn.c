/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:35 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/19 12:56:23 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		g_arr_len;
char	g_arr[10];

void	last_num(int start)
{
	char	temp;

	while (start <= 9)
	{
		temp = start + '0';
		write(1, &temp, 1);
		start++;
	}
}

void	take_num(int pre, int cnt)
{
	int	i;

	if (g_arr_len == cnt)
	{
		write(1, g_arr, g_arr_len);
		write(1, ", ", 2);
		return ;
	}
	if (pre == 9)
		return ;
	i = pre;
	while (++i <= 10 + cnt - g_arr_len)
	{
		g_arr[cnt] = i + '0';
		take_num(i, cnt + 1);
	}
}

void	ft_print_combn(int n)
{
	int	i;

	i = 0;
	g_arr_len = n;
	while (i < 10 - g_arr_len)
	{
		g_arr[0] = i + '0';
		take_num(i++, 1);
	}
	last_num (i);
}
