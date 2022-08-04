/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:19:10 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/28 23:32:02 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	char	*a;
	char	*b;

	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		a = str;
		b = to_find;
		while (*a == *b && *b)
		{
			a++;
			b++;
		}
		if (*b == 0)
			return (str);
		str++;
	}
	return (0);
}
