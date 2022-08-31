/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:45:27 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 17:32:09 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *s, char c)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb_word;

	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			nb_word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb_word);
}

static char	**free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ary;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	ary = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ary)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ary[i++] = ft_strndup(s, c);
			if (!ary)
				return (free_arr(ary));
			while (*s && *s != c)
				s++;
		}
	}
	ary[i] = 0;
	return (ary);
}
