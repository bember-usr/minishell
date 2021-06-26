/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:33:36 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:42:15 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mem;

	mem = (t_list *)malloc(sizeof(t_list));
	if (mem)
	{
		if (!content)
			mem->content = NULL;
		mem->content = content;
		mem->next = NULL;
		return (mem);
	}
	return (NULL);
}
