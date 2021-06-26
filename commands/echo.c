/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:42 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:59:43 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_home(char **env)
{
	char	*path;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	i = search_str("HOME", env);
	path = ft_strnew(1024);
	while (env[i][j + 5])
	{
		path[k] = env[i][j + 5];
		k++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

void	echo(t_all *all)
{
	int	i;

	i = 1;
	while (all->cmds[all->cmd_num][i])
	{
		if (all->cmds[all->cmd_num][i][0] == '~' \
				&& !all->cmds[all->cmd_num][i][1])
			ft_putendl(get_home(all->env));
		else if (!ft_strcmp(all->cmds[all->cmd_num][1], " -n "))
			ft_putstr(all->cmds[all->cmd_num][2]);
		else
			ft_putstr(all->cmds[all->cmd_num][i]);
		i++;
	}
	ft_putchar('\n');
}
