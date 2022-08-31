/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:30:04 by ljeong-           #+#    #+#             */
/*   Updated: 2022/08/30 17:26:07 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

int	ft_recursive_hex(t_format f, size_t n, size_t iteration)
{
	int		print_len;
	int		remainder;
	char	character;

	print_len = 0;
	if (n > 0 || (!iteration && !(f.specifier == 'p' && f.dot)))
	{
		remainder = n % 16;
		if (f.specifier == 'X')
			character = HEXUP[remainder];
		else
			character = HEXLOW[remainder];
		n /= 16;
		iteration = 1;
		print_len += ft_recursive_hex(f, n, iteration);
		print_len += ft_printchar(character);
	}
	return (print_len);
}

int	ft_print_hex(t_format f, unsigned long n, int len)
{
	int	print_len;

	print_len = 0;
	if (f.zero)
		print_len += ft_printnstr(ft_sharp(f), 2 * (f.sharp && !f.dot && n));
	if (!f.minus && f.zero && f.width > f.precision && (!f.dot || f.neg_prec))
		print_len += ft_printnchar('0', f.width - f.precision);
	else if (!f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	print_len += ft_printnstr(ft_sharp(f), 2 * (f.sharp && f.dot && n));
	if (!f.zero)
		print_len += ft_printnstr(ft_sharp(f), 2 * (f.sharp && n && !f.dot));
	print_len += ft_printnchar('0', f.precision - len);
	if (len)
		print_len += ft_recursive_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	return (print_len);
}

int	ft_print_x(t_format f, va_list ap)
{
	int				print_len;
	unsigned int	n;
	int				len;

	print_len = 0;
	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && (!f.precision && f.dot))
		len = 0;
	if (f.neg_prec || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.width -= 2;
	print_len += ft_print_hex(f, n, len);
	return (print_len);
}
