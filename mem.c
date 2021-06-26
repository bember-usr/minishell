/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:57:58 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 17:57:59 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**mal_dv(int size)
{
	char	**str;

	str = malloc(sizeof(char *) * size + 1);
	if (str == NULL)
	{
		fprintf(stderr, "lsh: ошибка выделения памяти\n");
		exit(EXIT_FAILURE);
	}
	str[size] = NULL;
	return (str);
}

char	***mal_tr(int size)
{
	char	***str;

	str = malloc(sizeof(char **) * size + 1);
	if (str == NULL)
	{
		fprintf(stderr, "lsh: ошибка выделения памяти\n");
		exit(EXIT_FAILURE);
	}
	str[size] = NULL;
	return (str);
}

char	*real(char **str, int size)
{
	*str = realloc(*str, size + 1);
	if (*str == NULL)
	{	
		fprintf(stderr, "lsh: ошибка выделения памяти\n");
		exit(EXIT_FAILURE);
	}
	return (*str);
}

char	**real_dv(char ***str, int size)
{
	*str = realloc(*str, size + 1);
	if (*str == NULL)
	{
		fprintf(stderr, "lsh: ошибка выделения памяти\n");
		exit(EXIT_FAILURE);
	}
	str[size] = NULL;
	return (*str);
}

char	***real_tr(char ****str, int size)
{
	*str = realloc(*str, size + 1);
	if (*str == NULL)
	{
		fprintf(stderr, "lsh: ошибка выделения памяти\n");
		exit(EXIT_FAILURE);
	}
	return (*str);
}
