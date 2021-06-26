/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:58:45 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:46 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*work_with_arra(t_all *all)
{
	char	*temp;

	while (spec_symbol(all, all->h1.c, '0', '0'))
		all->h1.c++;
	temp = all->prs.ptr + all->h1.c;
	while (spec_symbol(all, all->h1.c, '0', '0') != 1 \
			&& all->prs.ptr[all->h1.c] != '\0')
	{
		if (ft_strchr("\"\'", all->prs.ptr[all->h1.c]))
			set_flags(all, all->h1.c);
		all->h1.c++;
	}
	all->prs.ptr[all->h1.c] = '\0';
	all->h1.c++;
	return (ft_strdup(temp));
}

int	parser_spaces(t_all *all)
{
	if (check_if_end(all))
		return (all->h1.b);
	while (spec_symbol(all, all->prs.i + 1, ' ', '0'))
	{
		all->prs.i++;
		if (check_if_end(all))
			return (all->h1.b);
	}
	return (0);
}

int	work_with_dv(t_all *all)
{
	all->h1.b = 1;
	while (all->line[all->prs.i] != '\0' \
			&& (spec_symbol(all, all->prs.i, ';', '|') != 1))
	{
		if (all->line[all->prs.i] == '\\')
			all->prs.i++;
		else if (ft_strchr("\"\'", all->line[all->prs.i]))
			set_flags(all, all->prs.i);
		else if (spec_symbol(all, all->prs.i, ' ', '0'))
		{
			if (skip_start_spaces(all))
				continue ;
			else
			{
				if (parser_spaces(all))
					return (all->h1.b);
				else
					all->h1.b++;
			}
		}
		all->prs.i++;
	}
	all->prs.i++;
	return (all->h1.b);
}

int	ft_reduction_tr(t_all *all)
{
	if (all->line[all->i] == '\\')
		all->i++;
	else if (ft_strchr("\"\'", all->line[all->i]))
		set_flags(all, all->i);
	else if (spec_symbol(all, all->i, ';', '0'))
	{
		if (check_error(all, all->i, ';'))
			return (-1);
		if (check_end_on_spaces(all, all->i))
			return (all->h1.a);
		all->h1.a++;
	}
	else if (spec_symbol(all, all->i, '|', '0'))
	{
		if (check_error(all, all->i, '|'))
			return (0);
		all->h1.a++;
	}
	return (1);
}

int	work_with_tr(t_all *all)
{
	all->i = -1;
	if (all->line[all->i + 1] == '\0')
		all->h1.a = 0;
	while (all->line[++all->i] != '\0')
	{
		if (ft_reduction_tr(all))
			;
		else
			return (0);
	}
	if (all->prs.fdq != 0 || all->prs.fsq != 0)
		return (-1);
	return (all->h1.a);
}
