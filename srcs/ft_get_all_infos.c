/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/03 16:09:19 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_get_last(t_params *params, char *tmp)
{
	char	*str;

	if (params->neg == 1)
	{
		str = ft_strnjoin("-", tmp, 1, params->tmplen);
		params->tmplen++;
	}
	else
		str = ft_strndup(tmp, params->tmplen);
	return (str);
}

char	*ft_get_width(t_params *params, t_flags *flags, char *tmp)
//Applique la width
{
	int		diff;
	int		width;
	char	*str;

	if (params->width == 0)
		str = ft_strdup(tmp);
	else
	{
		diff = (params->width) - (params->tmplen) - (params->neg);
		width = params->width;
		if (width <= params->tmplen)
			str = ft_strdup(tmp);
		else 
		{
			if (!(str = (char*)ft_calloc(sizeof(char), (params->width + 1))))
				return (NULL);
			ft_memset(str, 0, ft_strlen(str));
			if (flags->zero == 1)
				ft_flag_zero(tmp, str, diff);
			else if (flags->minus == 1)
				ft_flag_minus(tmp, str, diff, params);
			else
				ft_no_flag(tmp, str, diff, params);
			params->tmplen = params->width - params->neg;
		}
	}
	params->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	free(tmp);
	return (str);
}

char	*ft_get_precision(t_params *params, char *tmp)
//Applique la précision
{
	int		diff;
	char	*str;

	
	if (params->prec == 0 || params->type == 'c' || params->type == 'p')
		str = ft_strdup(tmp);
	else
	{
		diff = 0;
		str = NULL;
		if (params->type == 's')
		{
			if (params->precision > params->tmplen)
				params->precision = params->tmplen;
			str = ft_strndup(tmp, params->precision);
			params->tmplen = params->precision;
		}
		else /*if (ft_strchr("diouxX", params->type))*/
		{
			if (!(strcmp(tmp, "0")) && params->precision == 0)
			{
				str = ft_strndup("", 0);
				params->tmplen = 0;
			}
			if (params->precision > (int)ft_strlen(tmp))
				str = ft_prec_apply(str, tmp, diff, params);
			else /*if (value <= len de tmp*/
				str = ft_strdup(tmp);
		}
	}
	params->precision = 0;
	params->prec = 0;
	free(tmp);
	return (str);
}

char    *ft_get_value(char *string, va_list list, int *param, t_flags *flags, t_params *params)
//Permet de récupérer les valeurs numériques (chiffre ou *)
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
			if (*param < 0 && !(params->prec))
			{
				*param *= -1;
				flags->minus = 1; 
			}
	}
    return (string);
}

char	*ft_get_info(t_params *params, t_flags *flags, char *string, va_list list)
//Remplit la structure avec les données
{
	while (*string)
	{
		string++;
		while(*string == '0' || *string == '-')
		{
			if (*string == '0')
				ft_zero(flags, string);
			if (*string == '-')
				ft_minus(flags, string);
			string++;
		}
		if ((*string >= '0' && *string <= '9') || *string == '*')
			string = ft_get_value(string, list, &params->width, flags, params);
		if (*string == '.')
		{
			flags->zero = 0;
			params->prec = 1;
			string++;
			if ((*string >= '0' && *string <= '9') || *string == '*')
				string = ft_get_value(string, list, &params->precision, flags, params);
			if (params->precision < 0)
				params->prec = 0;
		}	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
		if (ft_strchr("cspdiuxX%", *string))
		{
			params->type = *string;
			break ;
		}
	}
	if (flags->minus)
		flags->zero = 0;
	//printf("zero = %d\nminus = %d\nwidth = %d\nprecision = %d\n", flags->zero, flags->minus, params->width, params->precision);
	return (string);
}

void	ft_get_types(t_params *params, t_flags *flags, char **result, va_list list)
//Récupère les types, et applique précision & la width
{
	char	*tmp;
	char	*tmpwidth;
	char	*tmpprec;
	char	*tmplast;

	tmp = deal_with_type(params, list);
	params->tmplen = ft_strlen(tmp);
	if (params->type == 'c')
		params->tmplen = 1;
	//printf("tmp = %d\n", params->tmplen);

	tmpprec = ft_get_precision(params, tmp);
	tmpwidth = ft_get_width(params, flags, tmpprec);	
	tmplast = ft_get_last(params, tmpwidth);
	*result = ft_strfjoin(*result, tmplast, params->len, params->tmplen);
	params->len += params->tmplen;
}