/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:30:20 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 17:26:18 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	oper(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

int	ft_print_nbr(t_format f, char *nbr, int len)
{
	int	print_len;

	print_len = 0;
	f.width -= (f.space && !f.neg && !f.plus && f.width);
	if (f.neg || f.plus)
		print_len += ft_printnchar(oper(f), f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		print_len += ft_printnchar(' ', f.zero && !f.dot);
	if (!f.minus && f.zero && f.width > f.precision && (!f.dot || f.neg_prec))
		print_len += ft_printnchar('0', f.width - f.precision - f.neg - f.plus);
	else if (!f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision - f.neg - f.plus);
	if (f.neg || f.plus)
		print_len += ft_printnchar(oper(f), !f.zero || (f.dot && !f.neg_prec));
	else if (f.space)
		print_len += ft_printnchar(' ', !f.zero || f.dot);
	print_len += ft_printnchar('0', f.precision - len);
	print_len += write(1, nbr, len);
	if (f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision - f.neg - f.plus);
	return (print_len);
}

int	ft_print_u(t_format f, va_list ap)
{
	char			*nbr;
	unsigned int	n;
	int				print_len;
	int				len;

	print_len = 0;
	n = va_arg(ap, unsigned int);
	f.plus = 0;
	nbr = ft_uitoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && (!f.precision && f.dot))
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	print_len += ft_print_nbr(f, nbr, len);
	free(nbr);
	return (print_len);
}

int	ft_print_d_i(t_format f, va_list ap)
{
	char			*nbr;
	long long		n;
	int				print_len;
	int				len;

	print_len = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		f.neg = 1;
		f.plus = 0;
		n *= -1;
	}
	nbr = ft_litoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && (!f.precision && f.dot))
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	print_len += ft_print_nbr(f, nbr, len);
	free(nbr);
	return (print_len);
}
