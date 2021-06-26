/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:57:54 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:57:55 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_full(t_all *all)
{
	int	j;
	int	i;

	i = -1;
	while (++i < all->h1.a)
	{
		j = -1;
		while (++j < all->h1.b)
			free(all->cmds[i][j]);
		free(all->cmds[i]);
	}
	free(all->cmds);
}
