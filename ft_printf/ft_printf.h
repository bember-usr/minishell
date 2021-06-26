/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:36:13 by bember            #+#    #+#             */
/*   Updated: 2020/08/12 14:36:15 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_sspec
{
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	char		specifier;
}				t_sspec;

int				ft_printf(const char *format, ...);
t_sspec			ft_initsspec(void);
int				ft_specifier(char c);
int				ft_getwidth(const char **format, va_list argptr);
int				ft_getprec(const char **format, va_list argptr);
int				ft_printchar(char c, t_sspec spec);
int				ft_printstr(char *s, t_sspec spec);
int				ft_printnbr(int n, t_sspec spec, int flag);
int				ft_printunbr(unsigned int n, t_sspec spec);
int				ft_printx(unsigned int n, t_sspec spec);
int				ft_printptr(void *p, t_sspec spec);
t_sspec			ft_defflags(t_sspec spec, int *prec, int negnum);
char			*ft_arr(unsigned int n, int base, int prec);

#endif
