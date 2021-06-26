/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:43:02 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:39:56 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_numlen(unsigned long long res)
{
	size_t	i;

	i = 0;
	while (res)
	{
		res /= 10;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int					min;
	unsigned long long	res;
	int					i;

	min = 1;
	res = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		min *= (-1);
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		if (f_numlen(res) > 19)
		{
			if (min > 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return (res * min);
}
