/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/08 14:26:21 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int		copyandsearch(t_params *params, t_flags *flags, char *string, char **result, va_list list)
{
	while (*string)
	{
		if (*string == '%')
		{
			string = ft_get_info(params, flags, string, list);
			ft_get_types(params, flags, result, list);
			if (*(string + 1) == '\0')
				return (0);
			string++;
		}
		if (*string != '%')
		{
			*result = ft_strjoinchar(*result, *string, params->len);
			params->len++;
			string++;
		}
	}
	return (0);
}

int		ft_printf(const char *string, ...)
{
	va_list		list;
	t_params	params;
	t_flags		flags;
	char		*result;

	result = ft_strdup("");
	if (!string)
		return (0);
	ft_memset(&params, 0, sizeof(params));
	ft_memset(&flags, 0, sizeof(flags));
	va_start(list, string);
	copyandsearch(&params, &flags, (char*)string, &result, list);
	va_end(list);
	write(1, result, params.len);
	free(result);
	return (params.len);
}
