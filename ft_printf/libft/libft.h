/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:39:51 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/12 14:42:15 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *string, size_t range);
int					ft_isalnum(int a);
int					ft_isalpha(int letter);
int					ft_isascii(int a);
int					ft_isdigit(int num);
int					ft_isprint(int input);
void				*ft_memcpy(void *dest, const void *src, size_t range);
void				*ft_memmove(void *dest, const void *src, size_t range);
void				*ft_memset(void *string, int value, size_t range);
unsigned int		ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_strlen(const char *string);
unsigned int		ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_toupper(int character);
int					ft_tolower(int character);
char				*ft_strchr(const char *string, int character);
char				*ft_strrchr(const char *string, int character);
void				*ft_memchr(const void *string, int character, size_t range);
int					ft_memcmp(const void *string1, const void *string2,
						size_t range);
int					ft_atoi(const char *nptr);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *src);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
#endif