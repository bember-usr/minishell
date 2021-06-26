/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:28:31 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:44:31 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (s)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			if (s[i] == c)
				return ((char *)(s + i));
			i--;
		}
	}
	return (NULL);
}
