/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:27:11 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/25 15:52:10 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	front;
	int	back;
	int	temp;

	front = 0;
	back = size - 1;
	while (front < back)
	{
		temp = tab[front];
		tab[front] = tab[back];
		back[tab] = temp;
		front++;
		back--;
	}
}
