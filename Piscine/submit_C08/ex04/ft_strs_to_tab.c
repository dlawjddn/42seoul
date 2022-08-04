/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:13:26 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/02 16:24:23 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s;
	int			i;

	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s)
		return (0);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = (char *)malloc(sizeof(char) * (s[i].size + 1));
		s[i].copy = (char *)malloc(sizeof(char) * (s[i].size + 1));
		if (!s[i].str || !s[i].copy)
			return (0);
		ft_strcpy(s[i].str, av[i]);
		ft_strcpy(s[i].copy, s[i].str);
		i++;
	}
	s[i].str = 0;
	s[i].copy = 0;
	return (s);
}
