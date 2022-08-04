/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:17:51 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/06 14:59:01 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	dir;
	int	temp;

	dir = 0;
	while (length-- > 1)
	{
		temp = f(tab[length], tab[length - 1]);
		if (temp == 0)
			continue ;
		if (dir == 0)
			dir = temp;
		else if ((temp > 0 && dir < 0) || (temp < 0 && dir > 0))
			return (0);
	}
	return (1);
}
