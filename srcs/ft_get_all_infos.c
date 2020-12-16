/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/16 15:33:05 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_get_width(t_params *params, t_flags *flags, char *tmp)
//Applique la width
{
	int		diff;
	int		width;
	char	*str;

	if (params->width == 0)
		return (ft_strdup(tmp));
	diff = (params->width) - (params->tmplen);
	width = params->width;
	if (width <= params->tmplen)
		str = ft_strdup(tmp);
	else 
	{
		if (!(str = (char*)ft_calloc(sizeof(char), (params->width + 1))))
			return (NULL);
		if (flags->zero == 1)
			ft_flag_zero(tmp, str, diff);
		if (flags->minus == 1)
			str = ft_flag_minus(tmp, str, diff);
	}
	free(tmp);
	return (str);
}

char	*ft_get_precision(t_params *params, char *tmp)
//Applique la précision
{
	int		value;
	int		diff;
	char	*str;

	if (params->precision == 0)
		return (ft_strdup(tmp));
	value = params->precision;
	diff = 0;
	str = NULL;
	params->tmplen = params->precision;
	if (params->precision == 0)
		return (ft_strdup(tmp));
	if (params->type == 's')
		str = ft_strndup(tmp, value);
	else /*if (ft_strchr("diouxX", params->type))*/
	{
		if (value > (int)ft_strlen(tmp))
			str = ft_prec_apply(str, tmp, diff, value, params);
		else /*if (value <= len de tmp*/
			str = ft_strdup(tmp);
	}
	params->precision = 0;
	free(tmp);
	return (str);
}

char    *ft_get_value(char *string, va_list list, int *param)
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
			*param = va_arg(list, int);
    return (string);
}

char	*ft_get_info(t_params *params, t_flags *flags, char *string, va_list list)
//Remplit la structure avec les données
{
	while (*string)
	{
		string++;
		if (*string == '-')
			ft_minus(flags, string);
		if (*string == '0')
			ft_zero(flags, string);
		if ((*string >= '0' && *string <= '9') || *string == '*')
			string = ft_get_value(string, list, &params->width);
		if (*string == '.')
		{
			string++;
			if ((*string >= '0' && *string <= '9') || *string == '*')
				string = ft_get_value(string, list, &params->precision);
		}	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
		if (ft_strchr("cspdiuxX%", *string))
		{
			params->type = *string;
			break ;
		}
	}
	printf("zero = %d\nminus = %d\nwidth = %d\nprecision = %d\n", flags->zero, flags->minus, params->width, params->precision);
	return (string);
}

void	ft_get_types(t_params *params, t_flags *flags, char **result, va_list list)
//Récupère les types, et applique précision & la width
{
	char	*tmp;
	char	*tmpwidth;
	char	*tmpprec;

	tmp = deal_with_type(params, list);
	params->tmplen = ft_strlen(tmp);
	if (params->type == 'c')
		params->tmplen = 1;
	printf("tmp = %d\n", params->tmplen);

	tmpprec = ft_get_precision(params, tmp);
	printf("tmpprec = %d\n", params->tmplen);
	tmpwidth = ft_get_width(params, flags, tmpprec);	
	printf("tmpwidth = %d\n", params->tmplen);
	*result = ft_strfjoin(*result, tmpprec, params->len, params->tmplen);
	params->len += params->tmplen;
}