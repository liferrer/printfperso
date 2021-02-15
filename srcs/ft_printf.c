/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 12:09:34 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int		cpysrch(t_prm *prm, char *string, char **result, va_list list)
{
	while (*string)
	{
		if (*string == '%')
		{
			string = ft_get_info(prm, string, list);
			ft_get_types(prm, result, list);
			if (*(string + 1) == '\0')
				return (0);
			string++;
		}
		if (*string != '%')
		{
			*result = ft_strjoinchar(*result, *string, prm->len);
			prm->len++;
			string++;
		}
	}
	return (0);
}

int		ft_printf(const char *string, ...)
{
	va_list		list;
	t_prm		prm;
	char		*result;

	result = ft_strdup("");
	if (!string)
		return (0);
	ft_memset(&prm, 0, sizeof(prm));
	va_start(list, string);
	cpysrch(&prm, (char*)string, &result, list);
	va_end(list);
	write(1, result, prm.len);
	free(result);
	return (prm.len);
}
