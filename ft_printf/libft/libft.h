/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 23:41:31 by student           #+#    #+#             */
/*   Updated: 2021/04/12 17:33:06 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					check_bwr(int bwr, char *p_n);
int					get_next_line(int const fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
char				*ft_strnstr(const char *dst, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strtrim(const char *str, char const *set);
char				*ft_strstr(const char *dst, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					ft_cntwords(char const *str, char c);
int					ft_strcmpi(char *str1, char *str2);
int					ft_strcmp(char *str1, char *str2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *str);
void				ft_putstr(char const *str);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strrev(char *str);
void				ft_strclr(char *str);
void				ft_putchar(char c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_sqrt(int nbr);
t_list				*ft_lstnew(void *content);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
char				**ft_split(char const *s, char c);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstmap(t_list *lst, \
					void *(*f)(void *), void (*del)(void *));

#endif
