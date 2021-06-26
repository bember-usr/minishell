/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:58:36 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:37 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_unset_str(char *first, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (first[j] == env[i][j])
		{
			j++;
			if (first[j] == '\0' && env[i][j] == '=')
				return (i);
		}
		i++;
	}
	return (i);
}

char	**get_extra_env(char ***env)
{
	char	**str;
	t_h		h;

	h.i = 0;
	h.j = -1;
	while ((*env)[h.i])
		h.i++;
	str = mal_dv(h.i + 1);
	while (++h.j < h.i)
	{
		str[h.j] = ft_strdup((*env)[h.j]);
		free((*env)[h.j]);
	}
	free(*env);
	return (str);
}

char	**get_env(char **env)
{
	char	**str;
	t_h		h;

	h.i = 0;
	h.j = -1;
	while (env[h.i])
		h.i++;
	str = mal_dv(h.i);
	while (++h.j < h.i)
		str[h.j] = ft_strdup(env[h.j]);
	return (str);
}
