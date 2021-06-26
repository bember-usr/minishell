/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _export.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:49 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:59:50 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_cmd(t_all *all)
{
	int		i;

	if (!all->cmds[all->cmd_num][1])
	{
		print_env(all, 1);
		return ;
	}
	i = search_str(all->cmds[all->cmd_num][1], all->env);
	if (i < get_len_env(all->env))
	{
		free(all->env[i]);
		all->env[i] = ft_strdup(all->cmds[all->cmd_num][1]);
	}
	else if (check_str_on_sign(all->cmds[all->cmd_num][1]))
	{
		all->env = get_extra_env(&all->env);
		all->env[i] = ft_strdup(all->cmds[all->cmd_num][1]);
	}
}
