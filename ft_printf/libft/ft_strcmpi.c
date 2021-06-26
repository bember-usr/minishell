/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:02:20 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:41:57 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	t_strcmpi(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (ft_tolower(*str1) == ft_tolower(*str2))
		{
			str1++;
			str2++;
		}
		else
			return (*str1 - *str2);
	}
	return (*str1 - *str2);
}
