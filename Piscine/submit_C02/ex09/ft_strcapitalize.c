/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:24:24 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/29 09:54:27 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	upper_letter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	lower_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	char_func(char c)
{
	if (upper_letter(c))
		return (1);
	else if (lower_letter(c))
		return (1);
	else if (check_num(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (str);
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 'a' + 'A';
	i++;
	while (str[i])
	{
		if (lower_letter(str[i]) && (!char_func(str[i - 1])))
			str[i] -= 32;
		if (upper_letter(str[i]) && (char_func(str[i - 1])))
			str[i] += 32;
		i++;
	}
	return (str);
}
