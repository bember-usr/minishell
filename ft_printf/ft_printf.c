/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:38:25 by bember            #+#    #+#             */
/*   Updated: 2020/08/14 16:16:25 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sspec	ft_initsspec(void)
{
	t_sspec			spec;

	spec.minus = 0;
	spec.zero = 0;
	spec.width = 0;
	spec.dot = 0;
	spec.precision = 0;
	spec.specifier = 0;
	return (spec);
}

int	ft_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

static t_sspec	ft_get_spec(const char **format, va_list argptr, t_sspec spec)
{
	(*format)++;
	while (ft_specifier(**format) && **format != '\0')
	{
		if (**format == '-')
			spec.minus = 1;
		else if (**format == '0' && spec.zero == 0 && spec.minus == 0)
			spec.zero = 1;
		else if (**format == '*' || ft_isdigit(**format))
			spec.width = ft_getwidth(&(*format), argptr);
		else if (**format == '.')
		{
			spec.dot = 1;
			spec.precision = ft_getprec(&(*format), argptr);
		}
		else
			break ;
		(*format)++;
	}
	spec.specifier = **format;
	return (spec);
}

static int	ft_parse(va_list argptr, t_sspec spec)
{
	if (spec.specifier == 'c')
		return (ft_printchar(va_arg(argptr, int), spec));
	else if (spec.specifier == 's')
		return (ft_printstr(va_arg(argptr, char *), spec));
	else if (spec.specifier == 'd' || spec.specifier == 'i')
		return (ft_printnbr(va_arg(argptr, int), spec, 1));
	else if (spec.specifier == 'u')
		return (ft_printnbr(va_arg(argptr, unsigned int), spec, 0));
	else if (spec.specifier == 'p')
		return (ft_printptr(va_arg(argptr, void *), spec));
	else if (spec.specifier == 'x' || spec.specifier == 'X')
		return (ft_printx(va_arg(argptr, unsigned int), spec));
	else if (spec.specifier == '%')
		return (ft_printchar('%', spec));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			res;
	int			erres;
	t_sspec		spec;

	if (format == NULL)
		return (-1);
	res = 0;
	va_start(argptr, format);
	spec = ft_initsspec();
	while (*format != '\0')
	{
		erres = res;
		if (*format == '%')
			res += ft_parse(argptr, ft_get_spec(&format, argptr, spec));
		else
			res += ft_printchar(*format, spec);
		if (res < erres)
			res = -1;
		if (res < 0 || *format == '\0')
			break ;
		format++;
	}
	va_end(argptr);
	return (res);
}
