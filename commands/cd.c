/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:44 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:59:45 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*home_path(char *path, char **env)
{
	int	i;
	int	j;
	int	k;

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
	path[k] = '\0';
	return (path);
}

char	*get_old_path(char **env)
{
	int		i;
	char	*path;
	int		j;

	i = search_str("OLDPWD", env);
	path = ft_strnew(PATH_MAX);
	j = 0;
	while (env[i][j + 7])
	{
		path[j] = env[i][j + 7];
		j++;
	}
	ft_putendl(path);
	return (path);
}

char	*tilda_path(char **args, char **env)
{
	char	*path;
	int		i;
	int		j;

	path = home_path(path, env);
	i = ft_strlen(path);
	j = 1;
	while (args[1][j])
	{
		path[i] = args[1][j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

char	*get_path(char **args, char **env)
{
	char	*path;

	if (!args[1])
		path = home_path(path, env);
	else if (!ft_strcmp(args[1], "-"))
		path = get_old_path(env);
	else if (args[1][0] == '~')
		path = tilda_path(args, env);
	else
		path = ft_strdup(args[1]);
	return (path);
}

void	cd(char **args, t_all *all)
{
	char	*path;

	path = get_path(args, all->env);
	if (access(path, R_OK))
	{
		ft_printf("bash: cd: %s: Permission denied\n", path);
		free(path);
		return ;
	}
	if (access(path, F_OK) && ft_strcmp(path, "~"))
		ft_printf("%s %s%s\n", "bash: cd:", path, ": No such file or directory");
	chdir(path);
	free(path);
}
