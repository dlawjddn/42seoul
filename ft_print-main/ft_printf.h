/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:29:03 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/31 14:33:36 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

# define SPECIFIERS "cspdiuxX%"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
	int		neg;
	char	specifier;
}t_format;

int			ft_nbrlen(long n, int base);
int			ft_printnstr(char *str, int n);
int			ft_printnchar(int c, int n);
int			ft_printchar(int c);
int			ft_printf(const char *str, ...);
t_format	ft_newformat(void);
int			ft_print_format(t_format f, va_list ap);
int			ft_print_c_pct(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_u(t_format f, va_list ap);
int			ft_print_d_i(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_parse(char *str, va_list ap);
int			ft_recursive_hex(t_format f, size_t n, size_t iteration);
char		*ft_allocate(char *str, int len, unsigned int n);
char		*ft_uitoa(unsigned int n);
char		*ft_litoa(long long n);

#endif
