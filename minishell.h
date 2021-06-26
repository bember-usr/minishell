/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:53:25 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/12 18:01:44 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdint.h>
# include <sys/wait.h>
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

# define NSDF ": No such file or directory"
# define EXIT_SUCCESS 0
# define TRUE 1

typedef struct s_h
{
	int			i;
	int			j;
	int			c;
	int			b;
	int			a;
}				t_h;

typedef struct s_prs
{
	char		*ptr;
	int			i;
	int			fdq;
	int			fsq;
	int			fbs;
	int			num;
}				t_prs;

typedef struct s_all
{
	int			i;
	char		**env;
	char		*line;
	char		***cmds;
	int			cmd_num;
	t_prs		prs;
	t_h			h1;
}				t_all;



//parser
int		check_end_on_spaces(t_all *all, int i);
int		skip_start_spaces(t_all *all);
int		check_if_end(t_all *all);
int		spec_symbol(t_all *all, int i, char c, char s);
int		check_flags(t_all *all);
void	set_flags(t_all *all, int i);
void	init_data(t_all *all);
char	*work_with_arra(t_all *all);
int		work_with_dv(t_all *all);
int		work_with_tr(t_all *all);
int		check_str_on_sign(char *str);

//env
char	**get_env(char **env);
char	**get_extra_env(char ***env);
int		get_len_env(char **env);

//error
int		check_bwr(int bwr, char *p_n);
int		check_error(t_all *all, int i, char c);
int		error_found(char *str, char c, int i);
void	put_error(char *fstr, char *cmd, char *lstr);

//memory
char	*mal(int size);
char	**mal_dv(int size);
char	***mal_tr(int size);
char	*real(char **str, int size);
char	**real_dv(char ***str, int size);
char	***real_tr(char ****str, int size);
void	free_str2(char **str);
void	free_full(t_all *all);

//processing
void	do_commands(t_all *all);
char	**do_fork(t_all *all);
char	**ft_strtok(char *str);
void	execute(t_all *all);
int		search_str(char *first, char **env);
int		search_unset_str(char *first, char **env);
void	search_put_str(t_all *all);
char	*ft_mystr(char *first, char *second, char c);

//commands
void	export_cmd(t_all *all);
void	print_env(t_all *all, int fl);
void	unset(t_all *all);
void	cd(t_all *all);
void	exit_cmd(t_all *all);
void	echo(t_all *all);
void	pwd(void);

#endif
