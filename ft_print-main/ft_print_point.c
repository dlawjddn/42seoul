/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:24:47 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 17:26:30 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_pnt(t_format f, size_t n, size_t iteration)
{
	int	pnt_len;

	pnt_len = 1;
	if (n > 0 || !(iteration && f.dot))
	{
		if (n < 16)
			return (1);
		n /= 16;
		iteration = 1;
		pnt_len += count_pnt(f, n, iteration);
	}
	return (pnt_len);
}

int	ft_print_p(t_format f, va_list ap)
{
	int		print_len;
	size_t	n;
	int		len;

	print_len = 0;
	n = (size_t)va_arg(ap, void *);
	len = count_pnt(f, n, n);
	if (!n && (!f.precision && f.dot))
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	f.width -= 2;
	print_len += write(1, "0x", 2 * f.zero);
	if (!f.minus && f.width > f.precision && !f.dot && f.zero)
		print_len += ft_printnchar('0', (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', (f.width - f.precision));
	print_len += write(1, "0x", 2 * !f.zero);
	print_len += ft_printnchar('0', (f.precision - len) * (n != 0));
	print_len += ft_printnchar('0', f.precision * (f.dot && !n));
	if (len)
		print_len += ft_recursive_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision);
	return (print_len);
}
