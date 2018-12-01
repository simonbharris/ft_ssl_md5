/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:40:28 by sharris           #+#    #+#             */
/*   Updated: 2018/07/09 16:40:49 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define MALCHECK(x) if ((x) == NULL) { return (NULL); }

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Group 1 Libft Requirements
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char*s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isempty(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** Group 2 Libft Requirements
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** libft Bonus functions
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *newlst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Extra / Personal functions.
*/

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_iswhitespace(char c);
int				ft_wordcount(char *s);
int				ft_lstcount(t_list *lst);
int				ft_abs(int n);
void			*ft_realloc(void **ptr, size_t old_size, size_t new_size);
char			*ft_stpncpy(char *dst, const char *src, size_t len);
int				ft_mod(int nbr, int mod);
void			ft_lstdelone_f(void *content, size_t size);
void			ft_lstpush(t_list **alst, t_list *newlst);
char			*ft_itoabase(size_t nbr, char *base);
char			*ft_strffjoin(char **dst, char **src);
char			*ft_strcfjoin(const char *dst, char **src);
void			ft_putwstr(wchar_t *wstr);
wchar_t			*ft_wstrdup(const wchar_t *s1);
size_t			ft_wstrlen(const wchar_t *s);
wchar_t			*ft_wstrnew(size_t size);
wchar_t			*ft_wstrcpy(wchar_t *dst, const wchar_t *src);
int				ft_max(int i, int j);
wchar_t			*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2);
wchar_t			*ft_wstrffjoin(wchar_t **dst, wchar_t **src);
wchar_t			*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len);
char			*ft_lltoa(long long n);
long long		ft_hextoi(char *str);
char			*ft_strndup(const char *str, int n);
int				ft_parrlen(void **arr);
long long		ft_pow(long long nbr, int p);
t_list			*ft_strstolsts(char **strings);

/*
** Merge sort functs
*/

t_list			*ft_merge_sort(t_list *head,
								int cmp(void *, void *), int rev_flag);
int				merge_strcmp_f(void *s1, void *s2);

#endif
