/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liso <liso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:52:42 by liferrer          #+#    #+#             */
/*   Updated: 2021/01/11 16:06:40 by liso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define LOWHEXA "0123456789abcdef"
# define UPHEXA "0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_flags
{
	int minus;
	int	zero;
}	t_flags;

typedef struct		s_params
{
	char	type;
	int		width;
	int		prec;
	int		precision;
	int		neg;
	int		len;
	int		tmplen;
}	t_params;

void		*ft_calloc(size_t count, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memset(void *b, int c, size_t len);

int			ft_atoi(const char *s);
char		*ft_itoa(int n);
char		*ft_ultoa(int n);

char		*ft_strchr(char const *s, int c);

char		*ft_strdup(char const *s);
char		*ft_strndup(char const *s, size_t n);
char		*ft_strdups(const char *s);

char		*ft_strcat(char *s1, char *s2);
void		ft_strncat(char *s1, char *s2, int len1, int len2);

char		*ft_strfjoin(char *s1, char *s2, int len1, int len2);
char		*ft_strnjoin(char *s1, char *s2, int len1, int len2);
char		*ft_strjoinchar(char *s1, char c, int len);

size_t		ft_strlen(char const *s);

int			ft_printf(const char *string, ...);
int			copyandsearch(t_params *params, t_flags *flags, char *string, char **result, va_list list);
void		display(char *str);

void		ft_get_types(t_params *params, t_flags *flags, char **result, va_list list);
long		ft_get_size(unsigned long nb, int base);
char		*ft_get_info(t_params *params, t_flags *flags, char *string, va_list list);
char    	*ft_get_value(char *string, va_list list, int *param);
char		*ft_get_precision(t_params *params, char *tmp);
char		*ft_get_width(t_params *params, t_flags *flags, char *tmp);

char        *deal_with_type(t_params *params, va_list list);
char		*deal_with_char(char *tmp, va_list list);
char		*deal_with_string(char *tmp, va_list list);
char        *deal_with_pointers(va_list list);
char		*deal_with_hexa(unsigned long nb, char *base);

void    	ft_fill(char *s, char c, int nb);
char		*ft_prec_apply(char *str, char *tmp, int diff, int value, t_params *params);
void		ft_flag_zero(char *tmp, char *str, int diff);
void		ft_flag_minus(char *tmp, char *str, int diff, t_params *params);
void		ft_no_flag(char *tmp, char *str, int diff);
void 		ft_minus(t_flags *flags, char *string);
void 		ft_zero(t_flags *flags, char *string);


#endif