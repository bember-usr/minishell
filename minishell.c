/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:53:32 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:53:33 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_work(t_all *all)
{
	int	j;
	int	i;

	all->cmds = mal_tr(all->h1.a);
	i = -1;
	while (++i < all->h1.a)
	{
		j = -1;
		all->cmds[i] = mal_dv(work_with_dv(all));
		while (++j < all->h1.b)
			all->cmds[i][j] = work_with_arra(all);
	}
	free(all->line);
	do_commands(all);
	free_full(all);
}

void	loop(t_all *all)
{
	while (TRUE)
	{
		ft_putstr("Shell$> ");
		get_next_line(0, &all->line);
		init_data(all);
		if (work_with_tr(all) == -1)
			ft_printf("Error:\n");
		else
			main_work(all);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_all	all;

	if (argc == 1 && argv[0])
	{
		all.env = get_env(envp);
		loop(&all);
		return (0);
	}
	ft_printf("Wrong format input\n");
	return (1);
}
