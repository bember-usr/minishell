/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:49:03 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:43:44 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(dst);
	if (size > len)
	{
		size -= 1;
		while (*src != '\0' && size > len)
		{
			dst[len] = *src;
			src++;
			len++;
		}
		dst[len] = '\0';
		return (len + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
