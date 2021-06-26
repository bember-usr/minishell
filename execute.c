/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:58:23 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:24 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_comand(t_all *all, int i)
{
	if (i == 0)
		export_cmd(all);
	if (i == 1)
		print_env(all, 0);
	else if (i == 2)
		unset(all);
	else if (i == 4)
		exit_cmd(all);
	else if (i == 5)
		echo(all);
	else if (i == 6)
		pwd();
}

char	*ft_commands(int i)
{
	char	*command[7];

	command[0] = "export";
	command[1] = "env";
	command[2] = "unset";
	command[3] = "cd";
	command[4] = "exit";
	command[5] = "echo";
	command[6] = "pwd";
	return (command[i]);
}

void	execute(t_all *all)
{
	int		i;
	char	*str;

	i = -1;
	while (++i < 7)
	{
		str = ft_commands(i);
		if (!ft_strcmp(all->cmds[all->cmd_num][0], str))
		{
			execute_comand(all, i);
			break ;
		}
	}
}
