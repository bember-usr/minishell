/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:50:23 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:41:35 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pointer = *lst;
		while (pointer->next != NULL)
			pointer = pointer->next;
		pointer->next = new;
	}
}
