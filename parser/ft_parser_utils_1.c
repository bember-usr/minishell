/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:00:34 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/08 16:22:22 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	spec_symbol(t_all *all, int i, char c, char s)
{
	if (s == '0' && c != '0')
	{
		if (all->line[i] == c && all->line[i - 1] != '\\' && check_flags(all))
			return (1);
	}
	else if (s != '0' && c != '0')
	{
		if ((all->line[i] == c || all->line[i] == s) && \
			all->line[i - 1] != '\\' && check_flags(all))
			return (1);
	}
	else if (s == '0' && c == '0')
	{
		if ((all->line[i] == ' ' || all->line[i] == ';' || all->line[i] == '|') && \
			all->line[i - 1] != '\\' && check_flags(all))
			return (1);
	}
	return (0);
}

int	skip_start_spaces(t_all *all)
{
	if (all->prs.i == 0 || spec_symbol(all, all->prs.i - 1, ';', '|'))
	{
		while (all->line[all->prs.i] == ' ')
			all->prs.i++;
		return (1);
	}
	else
		return (0);
}

int	check_if_end(t_all *all)
{
	if (all->line[all->prs.i + 1] == '\0' \
		|| spec_symbol(all, all->prs.i + 1, ';', '|'))
	{
		all->prs.i += 2;
		return (all->h1.b);
	}
	else
		return (0);
}

int	check_end_on_spaces(t_all *all, int i)
{
	if (all->line[i + 1] == '\0')
		return (1);
	while (all->line[i + 1] == ' ')
	{
		i++;
		if (all->line[i + 1] == '\0')
			return (1);
	}
	return (0);
}
