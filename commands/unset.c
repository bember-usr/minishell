/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:38 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:59:39 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**new_env(char ***env, int minus)
{
	int		i;
	int		j;
	char	**env2;

	i = 0;
	j = 0;
	while ((*env)[i])
		i++;
	env2 = mal_dv(i - 1);
	i = 0;
	while ((*env)[j])
	{
		if (j != minus)
		{
			env2[i] = ft_strdup((*env)[j]);
			i++;
		}
		free((*env)[j]);
		j++;
	}
	free(*env);
	return (env2);
}

void	unset(t_all *all)
{
	int	i;

	if (!all->cmds[all->cmd_num][1])
		return ;
	i = search_unset_str(all->cmds[all->cmd_num][1], all->env);
	if (i > get_len_env(all->env))
		return ;
	all->env = new_env(&all->env, i);
}
