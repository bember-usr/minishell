/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:00:59 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/08 16:39:04 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_flags(t_all *all)
{
	if (all->prs.fdq == 0 && all->prs.fsq == 0)
		return (1);
	else
		return (0);
}

void	set_flags(t_all *all, int i)
{
	if (spec_symbol(all, i - 1, '\\', '0'))
		return ;
	else if ((all->line[i] == '\"' && all->prs.fdq == 1) \
			|| (all->line[i] == '\"' && all->prs.fsq == 1))
		all->prs.fdq = 0;
	else if (all->line[i] == '\"')
		all->prs.fdq = 1;
	else if ((all->line[i] == '\'' && all->prs.fsq == 1) \
			|| (all->line[i] == '\'' && all->prs.fdq == 1))
		all->prs.fsq = 0;
	else if (all->line[i] == '\'')
		all->prs.fsq = 1;
	else
		return ;
}
