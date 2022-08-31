/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:29:52 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 17:25:55 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnchar(int c, int n)
{
	int	print_len;

	print_len = 0;
	while (n-- > 0)
		print_len += (int)write(1, &c, 1);
	return (print_len);
}

int	ft_printnstr(char *str, int n)
{
	if (str != NULL)
		return ((int)write(1, str, n));
	return (0);
}

int	ft_print_c_pct(t_format f, va_list ap)
{
	char	c;
	int		print_len;

	print_len = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero && f.width > f.precision)
		print_len += ft_printnchar('0', f.width - f.precision);
	else if (!f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	print_len += ft_printchar(c);
	if (f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	return (print_len);
}

int	ft_print_s(t_format f, va_list ap)
{
	char	*string;
	int		print_len;

	print_len = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	if (!f.dot || f.precision > (int)ft_strlen(string) || f.neg_prec)
		f.precision = ft_strlen(string);
	if (!f.minus && f.zero && f.width > f.precision)
		print_len += ft_printnchar('0', f.width - f.precision);
	else if (!f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	print_len += ft_printnstr(string, f.precision);
	if (f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	return (print_len);
}
