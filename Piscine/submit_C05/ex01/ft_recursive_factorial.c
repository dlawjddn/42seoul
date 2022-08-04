/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:12:48 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/30 18:26:16 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_factorial(int nb)
{
	int	ans;

	ans = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		ans = nb * ft_recursive_factorial(nb - 1);
	return (ans);
}
