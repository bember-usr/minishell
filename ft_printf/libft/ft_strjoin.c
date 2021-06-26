/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:43:07 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:43:38 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	size_t		i;
	char		*mem;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (mem)
	{
		while (*s1 != '\0')
			mem[i++] = *s1++;
		while (*s2 != '\0')
			mem[i++] = *s2++;
		mem[i] = '\0';
	}
	return (mem);
}
