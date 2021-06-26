/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:27:42 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:44:26 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		i;
	char		*str_;
	char		*to_;
	size_t		len_str;

	str_ = (char *)str;
	to_ = (char *)to_find;
	len_str = ft_strlen(str_);
	if (to_find[0] == '\0')
		return (str_);
	i = 0;
	if (n > len_str)
		n = len_str;
	if (n >= ft_strlen(to_))
	{
		while (i + ft_strlen(to_) <= n)
		{
			if (ft_memcmp(str_ + i, to_, ft_strlen(to_)) == 0)
				return (str_ + i);
			i++;
		}
	}
	return (NULL);
}
