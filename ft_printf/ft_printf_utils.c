/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:41:13 by bember            #+#    #+#             */
/*   Updated: 2020/08/14 18:28:47 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sspec	ft_defflags(t_sspec spec, int *prec, int neg)
{
	if ((spec.width < 0 || spec.minus || (spec.dot && *prec >= 0)) \
		&& spec.zero)
		spec.zero = 0;
	if (spec.zero != 0)
	{
		*prec = spec.width;
		if (neg)
			(*prec)--;
		spec.width = 0;
	}
	return (spec);
}

int	ft_getwidth(const char **format, va_list argptr)
{
	int	width;

	width = 0;
	if (**format == '*')
		width = va_arg(argptr, int);
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	return (width);
}

int	ft_getprec(const char **format, va_list argptr)
{
	int	prec;

	prec = 0;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		prec = va_arg(argptr, int);
	}
	if (ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		prec = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (prec);
}

static int	ft_nlen(unsigned int nbr, int base, int prec)
{
	int	len;

	len = 1;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	if (prec > 2147483646)
		prec = 2147483646;
	if (prec > len)
		len = prec;
	return (len);
}

char	*ft_arr(unsigned int nbr, int base, int prec)
{
	int		i;
	int		len;
	char	*arr;
	char	*array;

	array = "0123456789abcdef";
	len = 0;
	len = ft_nlen(nbr, base, prec);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
		arr[i++] = '0';
	arr[len] = '\0';
	while (nbr / base != 0)
	{
		arr[--len] = array[nbr % base];
		nbr /= base;
	}
	arr[--len] = array[nbr % base];
	return (arr);
}
