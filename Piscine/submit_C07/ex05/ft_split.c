/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:07:05 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/02 17:21:52 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_check(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen3(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!is_check(str[i++], charset))
		j++;
	while (str[i])
	{
		if (!is_check(str[i], charset) && is_check(str[i - 1], charset))
			j++;
		i++;
	}
	return (j);
}

char	*ft_strncpy(char *src, int size)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	s = (char **)malloc(sizeof(char *) * (ft_strlen3(str, charset) + 1));
	if (!s)
		return (0);
	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (!is_check(str[i + j], charset))
			j++;
		if (j)
		{
			s[k] = ft_strncpy(str + i, j);
			k++;
		}
		i = i + j + 1;
	}
	s[k] = 0;
	return (s);
}
