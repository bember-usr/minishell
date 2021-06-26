/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:58:03 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:04 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_all *all)
{
	all->prs.ptr = all->line;
	all->prs.fdq = 0;
	all->prs.fsq = 0;
	all->prs.fbs = 0;
	all->prs.i = 0;
	all->h1.c = 0;
	all->h1.b = 1;
	all->h1.a = 1;
}
