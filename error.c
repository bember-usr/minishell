/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:58:32 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:33 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_found(char *str, char c, int i)
{
	ft_printf("%s", str);
	if (i == 1)
		ft_printf(" '%c'\n", c);
	else if (i == 2)
		ft_printf(" '%c'\n", c);
	return (-1);
}

void	check_spaces_after(t_all *all, int i, char c)
{
	i++;
	while (all->line[++i] == ' ')
		if (spec_symbol(all, i, ';', '|') || \
		(all->line[i] == '\0' && c == '|'))
			error_found("bash: syntax error", c, 1);
}

int	check_error(t_all *all, int i, char c)
{
	int	tmp;

	tmp = i;
	if (all->line[i + 1] == '\0' && c == '|')
		return (error_found("bash: syntax error near unexpected token", c, 1));
	else if (i == 0)
		return (error_found("bash: syntax error near unexpected token", c, 1));
	else if (spec_symbol(all, i + 1, ';', '|'))
		return (error_found("bash: syntax error near unexpected token", c, 2));
	else if (all->line[i + 1] == ' ')
	{
		check_spaces_after(all, i, c);
		i = tmp;
	}
	if (all->line[i - 1] == ' ')
	{
		i--;
		while (all->line[--i] == ' ')
			if (i == -1)
				return (error_found("bash: syntax", c, 1));
	}
	return (0);
}
