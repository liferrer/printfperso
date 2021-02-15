/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:52:42 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 12:04:51 by liferrer         ###   ########.fr       */
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

typedef struct	s_prm
{
	char	type;
	int		width;
	int		prec;
	int		precision;
	int		neg;
	int		len;
	int		tmplen;
	int		space;
	int		minus;
	int		zero;
}				t_prm;

void			*ft_calloc(size_t count, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

int				ft_atoi(const char *s);
char			*ft_itoa(int n, t_prm *prm);
char			*ft_ultoa(int n);

char			*ft_strchr(char const *s, int c);

char			*ft_strdup(char const *s);
char			*ft_strndup(char const *s, size_t n);
char			*ft_strdups(const char *s);

char			*ft_strcat(char *s1, char *s2);
void			ft_strncat(char *s1, char *s2, int len1, int len2);

char			*ft_strfjoin(char *s1, char *s2, int len1, int len2);
char			*ft_strnjoin(char *s1, char *s2, int len1, int len2);
char			*ft_strjoinchar(char *s1, char c, int len);

size_t			ft_strlen(char const *s);

int				ft_printf(const char *string, ...);
int				cpysrch(t_prm *prm, char *string, char **result, va_list list);
void			display(char *str);

void			ft_get_types(t_prm *prm, char **result, va_list list);
long			ft_get_size(unsigned long nb, int base);
char			*ft_get_info(t_prm *prm, char *string, va_list list);
char			*ft_get_info_prec(char *string, t_prm *prm, va_list list);
char			*ft_check_zero_minus(char *string, t_prm *prm);
char			*ft_get_vl(char *string, va_list list, int *param, t_prm *prm);
char			*ft_get_precision(t_prm *prm, char *tmp);
char			*ft_get_prc_nxt(t_prm *prm, char *tmp, char *str, int diff);
char			*ft_get_width(t_prm *prm, char *tmp);
char			*ft_get_wdth_nxt(t_prm *prm, char *tmp, char *str, int diff);
char			*ft_get_last(t_prm *prm, char *tmp);

char			*deal_with_type(t_prm *prm, va_list list);
char			*deal_with_char(char *tmp, va_list list);
char			*deal_with_string(char *tmp, va_list list);
char			*deal_with_pointers(va_list list);
char			*deal_with_hexa(unsigned long nb, char *base);

void			ft_fill(char *s, char c, int nb);
char			*ft_prec_apply(char *str, char *tmp, int diff, t_prm *prm);
void			ft_flag_zero(char *tmp, char *str, int diff);
void			ft_flag_minus(char *tmp, char *str, int diff, t_prm *prm);
void			ft_no_flag(char *tmp, char *str, int diff, t_prm *prm);
void			ft_minus(t_prm *prm, char *string);
void			ft_zero(t_prm *prm, char *string);
#endif
