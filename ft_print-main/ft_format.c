/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:29:25 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/30 15:58:15 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	ft_newformat(void)
{
	t_format	newformat;

	newformat.minus = 0;
	newformat.plus = 0;
	newformat.width = 0;
	newformat.precision = 0;
	newformat.specifier = 0;
	newformat.zero = 0;
	newformat.dot = 0;
	newformat.space = 0;
	newformat.sharp = 0;
	newformat.neg_prec = 0;
	newformat.neg = 0;
	return (newformat);
}
