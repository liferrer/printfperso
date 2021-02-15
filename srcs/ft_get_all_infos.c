/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 12:10:09 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char		*ft_get_last(t_prm *prm, char *tmp)
{
	char	*str;

	if (prm->neg == 1)
	{
		str = ft_strnjoin("-", tmp, 1, prm->tmplen);
		prm->tmplen++;
	}
	else if (prm->space == 1)
	{
		str = ft_strnjoin(" ", tmp, 1, prm->tmplen);
		prm->tmplen++;
	}
	else
		str = ft_strndup(tmp, prm->tmplen);
	return (str);
}

char		*ft_get_width(t_prm *prm, char *tmp)
{
	int		diff;
	int		width;
	char	*str;

	if (prm->width == 0)
		str = ft_strdup(tmp);
	else
	{
		diff = (prm->width) - (prm->tmplen) - (prm->neg);
		width = prm->width;
		if (width <= prm->tmplen)
			str = ft_strdup(tmp);
		else
		{
			if (!(str = (char*)ft_calloc(sizeof(char), (prm->width + 1))))
				return (NULL);
			str = ft_get_wdth_nxt(prm, tmp, str, diff);
		}
	}
	prm->width = 0;
	prm->minus = 0;
	prm->zero = 0;
	free(tmp);
	return (str);
}

char		*ft_get_precision(t_prm *prm, char *tmp)
{
	int		diff;
	char	*str;

	if (prm->prec == 0 || prm->type == 'c' || prm->type == 'p')
		str = ft_strdup(tmp);
	else
	{
		diff = 0;
		str = NULL;
		if (prm->type == 's')
		{
			if (prm->precision > prm->tmplen)
				prm->precision = prm->tmplen;
			str = ft_strndup(tmp, prm->precision);
			prm->tmplen = prm->precision;
		}
		else
			str = ft_get_prc_nxt(prm, tmp, str, diff);
	}
	prm->precision = 0;
	prm->prec = 0;
	free(tmp);
	return (str);
}

char		*ft_get_info(t_prm *prm, char *string, va_list list)
{
	while (*string)
	{
		string++;
		while (*string == ' ')
		{
			prm->space = 1;
			string++;
		}
		while (*string == '0' || *string == '-')
			string = ft_check_zero_minus(string, prm);
		if ((*string >= '0' && *string <= '9') || *string == '*')
			string = ft_get_vl(string, list, &prm->width, prm);
		if (*string == '.')
			string = ft_get_info_prec(string, prm, list);
		if (ft_strchr("cspdiuxX%", *string))
		{
			prm->type = *string;
			break ;
		}
	}
	if (prm->minus)
		prm->zero = 0;
	return (string);
}

void		ft_get_types(t_prm *prm, char **result, va_list list)
{
	char	*tmp;
	char	*tmpwidth;
	char	*tmpprec;
	char	*tmplast;

	tmp = deal_with_type(prm, list);
	if (prm->neg == 1)
		prm->space = 0;
	prm->tmplen = ft_strlen(tmp);
	if (prm->type == 'c')
		prm->tmplen = 1;
	tmpprec = ft_get_precision(prm, tmp);
	tmpwidth = ft_get_width(prm, tmpprec);
	tmplast = ft_get_last(prm, tmpwidth);
	*result = ft_strfjoin(*result, tmplast, prm->len, prm->tmplen);
	prm->len += prm->tmplen;
}
