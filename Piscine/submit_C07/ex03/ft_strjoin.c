/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:04:00 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/02 17:05:03 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		sum;

	if (size == 0)
		return (0);
	i = 0;
	sum = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		sum = sum + j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	sum = sum + i * (size - 1);
	return (sum);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	s = (char *)malloc(sizeof(char) * (ft_strlen(size, strs, sep) + 1));
	if (!s)
		return (0);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			s[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < (size - 1))
			s[k++] = sep[j++];
		i++;
	}
	s[k] = 0;
	return (s);
}
