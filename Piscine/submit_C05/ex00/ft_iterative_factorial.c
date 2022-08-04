/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:56:29 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/29 18:48:44 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	i;
	int	ans;

	i = nb;
	ans = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i >= 1)
		ans = ans * i--;
	return (ans);
}
