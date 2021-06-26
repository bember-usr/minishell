/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:46 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:59:47 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_dqw(char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		j = 0;
		printf("declare -x ");
		while (env[i][j] != '\0')
		{
			if (env[i][j] == '=')
			{
				printf("%c\"", env[i][j]);
				while (env[i][++j])
					printf("%c", env[i][j]);
				printf("\"");
			}
			else
				printf("%c", env[i][j++]);
		}
		printf("\n");
	}
}

void	sort_array(t_all *all, int len)
{
	char	*tmp;
	int		i;
	int		j;
	char	**str;

	i = 0;
	str = get_env(all->env);
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strncmp(str[j], str[j + 1], ft_strlen(str[j]) + 1) > 0)
			{
				tmp = str[j + 1];
				str[j + 1] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = -1;
	put_dqw(str);
}

int	get_len_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		;
	return (i);
}

void	print_env(t_all *all, int fl)
{
	int		i;

	i = -1;
	if (all->cmds[all->cmd_num][1] != NULL)
		put_error("env: ", all->cmds[all->cmd_num][1], NSDF);
	else if (fl == 0)
		while (all->env[++i])
			ft_putendl(all->env[i]);
	else if (fl == 1)
		sort_array(all, get_len_env(all->env));
}
