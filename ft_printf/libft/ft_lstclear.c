/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:03:09 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:41:46 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	if (lst)
	{
		while ((*lst) != NULL)
		{
			new = (*lst)->next;
			if (del)
				(*del)((*lst)->content);
			(*lst)->next = NULL;
			free(*lst);
			*lst = new;
		}
	}
}
