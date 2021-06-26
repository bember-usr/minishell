/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:18:56 by bember            #+#    #+#             */
/*   Updated: 2020/08/14 18:18:58 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int n, t_sspec spec)
{
	char	*arr;
	int		res;
	int		prec;
	int		i;

	i = -1;
	prec = spec.precision;
	spec = ft_defflags(spec, &prec, 0);
	if (spec.dot && prec == 0 && n == 0 && spec.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_arr(n, 16, prec);
	if (arr == NULL)
		return (-1);
	if (spec.specifier == 'X')
	{
		while (arr[++i])
			arr[i] = ft_toupper(arr[i]);
	}
	res = ft_printstr(arr, spec);
	free(arr);
	return (res);
}
