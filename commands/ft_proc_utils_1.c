/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:39 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:59:40 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_error(char *fstr, char *cmd, char *lstr)
{
	ft_putstr_fd(fstr, 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(lstr, 2);
}

char	*ft_mystr(char *first, char *second, char c)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = ft_strlen(first);
	j = ft_strlen(second);
	str = ft_strnew(i + j + 1);
	k = 0;
	while (k < i)
	{
		str[k] = first[k];
		k++;
	}
	str[k] = c;
	i = 0;
	k++;
	while (i < j)
	{
		str[k] = second[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

void	search_put_str(t_all *all)
{
	int	i;
	int	k;

	i = search_str(all->cmds[all->cmd_num][1] + 1, all->env);
	k = 0;
	if (all->env[i])
	{
		while (all->env[i][k] != '=')
			k++;
		k++;
		while (all->env[i][k])
		{
			ft_putchar(all->env[i][k]);
			k++;
		}
	}
	ft_putchar('\n');
}

int	search_str(char *first, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (first[j] && env[i][j] != '=' && (first[j] == env[i][j]))
		{
			j++;
			if (first[j] == '=' && env[i][j] == '=')
				return (i);
		}
		i++;
	}
	return (i);
}

int	check_str_on_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '=')
		return (1);
	else if (str[i] == '\0')
		return (0);
	return (0);
}
