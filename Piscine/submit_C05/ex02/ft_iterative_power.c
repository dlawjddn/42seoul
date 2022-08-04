/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:20:57 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/01 14:27:11 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	ans;

	i = 0;
	ans = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i++ < power)
		ans = ans * nb;
	return (ans);
}
