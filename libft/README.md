# Libft

## How to use

### Make

``` make -C ${LIBFTDIR}/ ```

### Compilation

#### Library
- ``` -L ${LIBFTDIR}/ -l ft ```

#### Include
- ``` -I ${LIBFTDIR}/includes/ ```

## All function

[char.h](includes/char.h)

|	function	|	prototype	|
|	:---:	|	:---:	|
|	[ft_isalpha](./srcs/char/ft_isalpha.c)	|	int	ft_isalpha(int c);	|
|	[ft_isalnum](./srcs/char/ft_isalnum.c)	|	int	ft_isalnum(int c);	|
|	[ft_isascii](./srcs/char/ft_isascii.c)	|	int	ft_isascii(int c);	|
|	[ft_isdigit](./srcs/char/ft_isdigit.c)	|	int	ft_isdigit(int c);	|
|	[ft_isprint](./srcs/char/ft_isprint.c)	|	int	ft_isprint(int c);	|
|	[ft_tolower](./srcs/char/ft_tolower.c)	|	int	ft_toupper(int c);	|
|	[ft_toupper](./srcs/char/ft_toupper.c)	|	int	ft_tolower(int c);	|

[mem.h](includes/mem.h)

|	function	|	prototype	|
|	:---: |	:---: |
|	[ft_memset](./srcs/mem/ft_memset.c)		|	void	*ft_memset(void *s, int c, size_t n);					|
|	[ft_bzero](./srcs/mem/ft_bzero.c)		|	void	ft_bzero(void *s, size_t n);							|
|	[ft_memcpy](./srcs/mem/ft_memcpy.c)		|	void	*ft_memcpy(void *dest, const void *src, size_t n);		|
|	[ft_mempcpy](./srcs/mem/ft_memcpy.c)	|	void	*ft_mempcpy(void *dest, const void *src, size_t n);		|
|	[ft_memmove](./srcs/mem/ft_memmove.c)	|	void	*ft_memmove(void *dest, const void *src, size_t n);		|
|	[ft_memchr](./srcs/mem/ft_memchr.c)		|	void	*ft_memchr(const void *s, int c, size_t n);				|
|	[ft_memcmp](./srcs/mem/ft_memcmp.c)		|	int		ft_memcmp(const void *s1, const void *s2, size_t n);	|
|	[ft_calloc](./srcs/mem/ft_calloc.c)		|	void	*ft_calloc(size_t nmemb, size_t size);					|
|	[ft_nfree](./srcs/mem/ft_nfree.c)		|	void	ft_nfree(void **ptr);									|
|	[ft_memdump](./srcs/mem/ft_memdump.c)	|	void	 ft_memdump(void *ptr, size_t len);						|

[num.h](includes/num.h)

|	function	|	prototype	|
|	:---:	|	:---:	|
|	[ft_atoi](./srcs/num/ft_atoi.c)		|	int		ft_atoi(const char *nptr);		|
|	[ft_atol](./srcs/num/ft_atol.c)		|	long	ft_atol(const char *nptr);		|
|	[ft_maxf](./srcs/num/ft_min_max.c)	|	float	ft_maxf(float n1, float n2);	|
|	[ft_minf](./srcs/num/ft_min_max.c)	|	float	ft_minf(float n1, float n2);	|
|	[ft_absf](./srcs/num/ft_abs.c)		|	float	ft_absf(float n);				|
|	[ft_abs](./srcs/num/ft_abs.c)		|	int		ft_abs(int n);					|
|	[ft_min](./srcs/num/ft_min_max.c)	|	int		ft_min(int n1, int n2);			|
|	[ft_max](./srcs/num/ft_min_max.c)	|	int		ft_max(int n1, int n2);			|

[str.h](includes/str.h)

|	function	|	prototype	|
|	:---:	|	:---:	|
|	[ft_strlen](./srcs/str/ft_strlen.c)			|	size_t	ft_strlen(const char *s);										|
|	[ft_strlcpy](./srcs/str/ft_strcpy.c)		|	size_t	ft_strlcpy(char *dst, const char *src, size_t size);			|
|	[ft_strlcat](./srcs/str/ft_strlcat.c)		|	size_t	ft_strlcat(char *dst, const char *src, size_t size);			|
|	[ft_strchr](./srcs/str/ft_strchr.c)			|	char	*ft_strchr(const char *s, int c);								|
|	[ft_strrchr](./srcs/str/ft_strrchr.c)		|	char	*ft_strrchr(const char *s, int c);								|
|	[ft_strncmp](./srcs/str/ft_strncmp.c)		|	int		ft_strncmp(const char *s1, const char *s2, size_t n);			|
|	[ft_strnstr](./srcs/str/ft_strnstr.c)		|	char	*ft_strnstr(const char *big, const char *little, size_t len);	|
|	[ft_strdup](./srcs/str/ft_strdup.c)			|	char	*ft_strdup(const char *s);										|
|	[ft_substr](./srcs/str/ft_substr.c)			|	char	*ft_substr(const char *s, unsigned int start, size_t len);		|
|	[ft_strjoin](./srcs/str/ft_strjoin.c)		|	char	*ft_strjoin(char const *s1, char const *s2);					|
|	[ft_strtrim](./srcs/str/ft_strtrim.c)		|	char	*ft_strtrim(char const *s1, char const *set);					|
|	[ft_strmapi](./srcs/str/ft_strmapi.c)		|	char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));		|
|	[ft_striteri](./srcs/str/ft_striteri.c)		|	void	ft_striteri(char *s, void (*f)(unsigned int, char*));			|
|	[ft_split](./srcs/str/ft_split.c)			|	char	**ft_split(char const *s, char c);								|
|	[ft_itoa](./srcs/str/ft_itoa.c)				|	char	*ft_itoa(int n);												|
|	[t_strncpy](./srcs/str/ft_strcpy.c)			|	void	ft_strncpy(char *dest, const char *src, size_t n);				|
| 	[ft_stpcpy](./srcs/str/ft_strcpy.c)			|	char	*ft_stpcpy(char *dest, const char *src);						|
| 	[ft_strcpy](./srcs/str/ft_strcpy.c)			|	char	*ft_strcpy(char *dest, const char *src);						|
|	[ft_strisnumber](./srcs/str/ft_strisnum.c)	|	int		ft_strisnumber(const char *s);									|
|	[ft_strsfree](./srcs/str/ft_split.c)		|	void	ft_strsfree(char **str);										|
|	[ft_strsjoin](./srcs/str/ft_strsjoin.c)		|	char	*ft_strsjoin(char **strs);										|
|	[ft_strsjoin_c](./srcs/str/ft_strsjoin_c.c)	|	char	*ft_strsjoin_c(char **strs, char sep);							|

[put.h](includes/put.h)

|	function	|	prototype	|
|	:---:	|	:---:	|
|	[ft_putchar_fd](./srcs/put/ft_putchar_fd.c)	|	void	ft_putchar_fd(char c, int fd);	|
|	[ft_putstr_fd](./srcs/put/ft_putstr_fd.c)	|	void	ft_putstr_fd(char *s, int fd);	|
|	[ft_putendl_fd](./srcs/put/ft_putendl_fd.c)	|	void	ft_putendl_fd(char *s, int fd);	|
|	[ft_putnbr_fd](./srcs/put/ft_putnbr_fd.c)	|	void	ft_putnbr_fd(int n, int fd);	|

[ft_printf.h](includes/ft_printf.h)

|	function	|	prototype	|
|	:---:	|	:---:	|
|	[ft_printf](./srcs/ft_printf/ft_printf.c)		|	int		ft_printf(const char *str, ...);					|
|	[ft_printchar](./srcs/ft_printf/ft_printchar.c)	|	size_t	ft_printchar(int c);								|
|	[ft_printstr](./srcs/ft_printf/ft_printstr.c)	|	size_t	ft_printstr(char *str);								|
|	[ft_printnbr](./srcs/ft_printf/ft_printnbr.c)	|	size_t	ft_printnbr(long long lnbr);						|
|	[ft_printxnbr](./srcs/ft_printf/ft_printxnbr.c)	|	size_t	ft_printxnbr(unsigned long long lnbr, char *xset);	|
|	[ft_printptr](./srcs/ft_printf/ft_printptr.c)	|	size_t	ft_printptr(unsigned long long llnbr);				|

[list.h](includes/list.h)

|	function	|	prototype	|
|	:---:	|	:---:	|
|	[ft_lstnew](./srcs/list/ft_lstnew.c)				|	t_list	*ft_lstnew(void *content);	|
|	[ft_lstadd_front](./srcs/list/ft_lstadd_front.c)	|	void	ft_lstadd_front(t_list **lst, t_list *new);	|
|	[ft_lstsize](./srcs/list/ft_lstsize.c)				|	int		ft_lstsize(t_list *lst);	|
|	[ft_lstlast](./srcs/list/ft_lstlast.c)				|	t_list	*ft_lstlast(t_list *lst);	|
|	[ft_lstadd_back](./srcs/list/ft_lstadd_back.c)		|	void	ft_lstadd_back(t_list **lst, t_list *new);	|
|	[ft_lstdelone](./srcs/list/ft_lstdelone.c)			|	void	ft_lstdelone(t_list *lst, void (*del)(void *));	|
|	[ft_lstclear](./srcs/list/ft_lstclear.c)			|	void	ft_lstclear(t_list **lst, void (*del)(void *));	|
|	[ft_lstiter](./srcs/list/ft_lstiter.c)				|	void	ft_lstiter(t_list *lst, void (*f)(void *));	|
|	[ft_lstmap](./srcs/list/ft_lstmap.c)				|	t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));	|
|	[ft_lstpop](./srcs/list/ft_lstpop.c)				|	void	*ft_lstpop(t_list **lst);	|
|	[ft_lstpush](./srcs/list/ft_lstpush.c)				|	int		ft_lstpush(t_list **lst, void *data);	|
|	[ft_lstshift](./srcs/list/ft_lstshift.c)			|	void	*ft_lstshift(t_list **lst);	|
|	[ft_lstunshift](./srcs/list/ft_lstunshift.c)		|	int		ft_lstunshift(t_list **lst, void *data);	|

[get_next_line.h](includes/get_next_line.h)

|	function	|	prototype 	|
|	:---:	|	:---:	|
|	[get_next_line](./srcs/gnl/get_next_line.c)	|	char	*get_next_line(int fd);	|

[arr.h](includes/arr.h)

|	function	|	prototype 	|
|	:---:	|	:---:	|
|	[ft_arr_clear](srcs/arr/ft_arr_clear.c)		|	char	*ft_arr_clear(t_array *array, void (*del)(void *));						|
|	[ft_arr_resize](srcs/arr/ft_arr_resize.c)	|	int		ft_arr_resize(t_array *array, size_t ncapacity);						|
|	[ft_arr_new](srcs/arr/ft_arr_new.c)			|	t_array	*ft_arr_new(size_t capacity);											|
|	[ft_arr_free](srcs/arr/ft_arr_free.c)		|	void	ft_arr_free(t_array **array, void (*del)(void *));						|
|	[ft_arr_push](srcs/arr/ft_arr_push.c)		|	int		ft_arr_push(t_array *array, void *elem);								|
|	[ft_arr_pop](srcs/arr/ft_arr_pop.c)			|	void	*ft_arr_pop(t_array *array);											|
|	[ft_arr_unshift](srcs/arr/ft_arr_unshift.c)	|	int		ft_arr_unshift(t_array *array, void *elem);								|
|	[ft_arr_shift](srcs/arr/ft_arr_shift.c)		|	void	*ft_arr_shift(t_array *array);											|
|	[ft_arr_map](srcs/arr/ft_arr_map.c)			|	t_array	*ft_arr_map(t_array *array, void *(*f)(void *), void (*del)(void *));	|
|	[ft_arr_append](srcs/arr/ft_arr_append.c)	|	int		ft_arr_append(t_array *arr, void *elem);								|

[vector.h](includes/vector.h)

|	function	|	prototype 	|
|	:---:	|	:---:	|
|	[ft_vec_init](srcs/vec/ft_vec_init.c)		|	int			ft_vec_init(t_vector *vector, size_t elem_size);		|
|	[ft_vec_new](srcs/vec/ft_vec_new.c)			|	t_vector	*ft_vec_new(size_t	elem_size);							|
|	[ft_vec_append](srcs/vec/ft_arr_new.c)		|	int			ft_vec_append(t_vector *vector, void *elem);			|
|	[ft_vec_resize](srcs/vec/ft_vec_resize.c)	|	int			ft_vec_resize(t_vector *vector, size_t	ncapacity);		|
|	[ft_vec_clear](srcs/vec/ft_vec_clear.c)		|	int			ft_vec_clear(t_vector *vector);							|
|	[ft_vec_get](srcs/vec/ft_vec_get.c)			|	int			ft_vec_get(t_vector *vector, size_t index, void *out);	|
|	[ft_vec_destroy](srcs/vec/ft_vec_destroy.c)	|	void		ft_vec_destroy(t_vector *vector);						|
|	[ft_vec_free](srcs/vec/ft_vec_free.c)		|	void		ft_vec_free(t_vector **vector);							|
