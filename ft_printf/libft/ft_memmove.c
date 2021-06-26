/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:29:32 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:42:45 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*s_1;
	const unsigned char	*s_2;
	size_t				i;

	if (!s1 && !s2)
		return (NULL);
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	if (s_2 < s_1)
	{
		while (++i <= n)
			s_1[n - i] = s_2[n - i];
	}
	if (s_2 > s_1)
	{
		while (n-- > 0)
			*(s_1++) = *(s_2++);
	}
	return (s1);
}
