/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:58:38 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:39 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_commands(t_all *all)
{
	all->cmd_num = 0;
	while (all->cmds[all->cmd_num])
	{
		execute(all);
		all->cmd_num++;
	}
}
