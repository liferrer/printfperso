/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_all_infos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 12:10:40 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_check_zero_minus(char *string, t_prm *prm)
{
	if (*string == '0')
		ft_zero(prm, string);
	if (*string == '-')
		ft_minus(prm, string);
	string++;
	return (string);
}

char	*ft_get_info_prec(char *string, t_prm *prm, va_list list)
{
	prm->zero = 0;
	prm->prec = 1;
	string++;
	if ((*string >= '0' && *string <= '9') || *string == '*')
		string = ft_get_vl(string, list, &prm->precision, prm);
	if (prm->precision < 0)
		prm->prec = 0;
	return (string);
}

char	*ft_get_wdth_nxt(t_prm *prm, char *tmp, char *str, int diff)
{
	ft_memset(str, 0, ft_strlen(str));
	if (prm->zero == 1)
		ft_flag_zero(tmp, str, diff);
	else if (prm->minus == 1)
		ft_flag_minus(tmp, str, diff, prm);
	else
		ft_no_flag(tmp, str, diff, prm);
	prm->tmplen = prm->width - prm->neg;
	return (str);
}

char	*ft_get_prc_nxt(t_prm *prm, char *tmp, char *str, int diff)
{
	if (!(strcmp(tmp, "0")) && prm->precision == 0)
	{
		str = ft_strndup("", 0);
		prm->tmplen = 0;
	}
	if (prm->precision > (int)ft_strlen(tmp))
		str = ft_prec_apply(str, tmp, diff, prm);
	else
		str = ft_strdup(tmp);
	return (str);
}

char	*ft_get_vl(char *string, va_list list, int *param, t_prm *prm)
{
	*param = 0;
	if (*string >= '0' && *string <= '9')
	{
		while (*string >= '0' && *string <= '9')
		{
			*param = *param * 10 + (*string - '0');
			string++;
		}
	}
	else if (*string == '*')
	{
		*param = va_arg(list, int);
		if (*param < 0 && !(prm->prec))
		{
			*param *= -1;
			prm->minus = 1;
		}
	}
	return (string);
}
