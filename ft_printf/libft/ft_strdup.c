/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:15:28 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:43:34 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (mem)
	{
		while (*s != '\0')
			mem[i++] = *s++;
	}
	else
		return (NULL);
	mem[i] = '\0';
	return (mem);
}
