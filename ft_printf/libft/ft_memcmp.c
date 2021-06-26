/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:17:38 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:42:36 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*s_1;
	unsigned char	*s_2;

	i = 0;
	j = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while (n--)
	{
		if (s_1[i] != s_2[j])
			return (s_1[i] - s_2[j]);
		i++;
		j++;
	}
	return (0);
}
