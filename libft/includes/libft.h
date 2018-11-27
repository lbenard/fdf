/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:43:39 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 18:28:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char	t_u8;
typedef char			t_i8;

/*
** list struct
*/

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

/*
** CG structs
*/

typedef struct			s_usize
{
	size_t	x;
	size_t	y;
}						t_usize;

typedef struct			s_isize
{
	ssize_t	x;
	ssize_t	y;
}						t_isize;

typedef struct			s_vec2f
{
	float	x;
	float	y;
}						t_vec2f;

typedef struct			s_vec3f
{
	float	x;
	float	y;
	float	z;
}						t_vec3f;

typedef struct			s_vec4f
{
	float	x;
	float	y;
	float	z;
	float	w;
}						t_vec4f;

typedef struct			s_mat3
{
	float	m[3][3];
}						t_mat3;

typedef struct			s_mat4
{
	float	m[4][4];
}						t_mat4;

/*
** libc functions
*/

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
	size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

/*
** second part functions
*/

void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(const char *s,
	char (*f)(unsigned int, char));
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *s, unsigned int start,
	size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s);
char					**ft_strsplit(const char *s, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(const char *s);
void					ft_putendl(const char *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnbr_fd(int n, int fd);

/*
** bonus functions
*/

t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list*));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list*));

/*
** additionnal libc functions
*/

char					*ft_strndup(const char *s1, size_t n);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_islower(int c);
size_t					ft_strnlen(const char *s, size_t maxlen);
int						ft_abs(int i);

/*
** personnal functions
*/

int						ft_min(int a, int b);
int						ft_max(int a, int b);
size_t					ft_nblen(int n);

char					*ft_lststrjoin(const t_list *lst,
	const char *separator);
t_list					*ft_lstfind(const t_list *lst, const void *to_find,
	int (*cmp)(const void*, const void*));
t_list					*ft_lstcontentfind(const t_list *lst,
	const void *to_find, size_t to_find_size);
t_list					*ft_lstpushback(t_list **list, t_list *new);
t_list					*ft_lstlast(const t_list *list);
void					ft_lstfree(t_list **list);
void					ft_lstremove(t_list **list, t_list *to_remove);

t_usize					ft_usize(size_t x, size_t y);
t_isize					ft_isize(ssize_t x, ssize_t y);
t_vec2f					ft_vec2f(float x, float y);
t_vec3f					ft_vec3f(float x, float y, float z);
t_vec4f					ft_vec4f(float x, float y, float z, float w);
t_mat3					ft_mat3(void);
t_mat3					ft_mat3_identity(void);
void					ft_print_mat3(t_mat3 *mat);
t_mat4					ft_mat4(void);
t_mat4					ft_mat4_identity(void);
void					ft_print_mat4(t_mat4 *mat);

#endif