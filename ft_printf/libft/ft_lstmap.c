/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 23:58:41 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:42:08 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ret;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	ret = new_lst;
	while (lst)
	{
		if (lst->next)
		{
			new_lst->next = ft_lstnew(f(lst->next->content));
			if (!new_lst)
			{
				ft_lstclear(&ret, del);
				return (0);
			}
			new_lst = new_lst->next;
		}
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (ret);
}
