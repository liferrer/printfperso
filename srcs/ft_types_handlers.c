/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liso <liso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/01/12 13:25:36 by liso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char		*deal_with_hexa(unsigned long nb, char *base)
{
    char	*str;
    int		i;

    i = ft_get_size(nb, 16) - 1;
    if (!(str = malloc(sizeof(char) * (ft_get_size(nb, 16) + 1))))
        return NULL;
    str[ft_get_size(nb, 16)] = '\0';
    while ((long)nb >= 0 && i >= 0)
    {
        str[i] = base[nb % 16];
        nb /= 16;
        i--;
    }
    return (str);
}

char        *deal_with_pointers(va_list list)
{
    char	*hexanum;
    char	*result;
	void	*ptr;

	ptr = va_arg(list, void*);
	if (!ptr)
		return (result = ft_strdup("0x0"));
    hexanum = deal_with_hexa((unsigned long)ptr, LOWHEXA);
    result = ft_strnjoin("0x1", hexanum, 3, ft_strlen(hexanum));
    return (result);
}

char		*deal_with_char(char *tmp, va_list list)
{
	if (!(tmp = (char *)malloc(sizeof(char) * 2)))
			return NULL;
	tmp[0] = va_arg(list, int);
	tmp[1] = '\0';
	return (tmp);
}

char        *deal_with_type(t_params *params, va_list list)
//Récupère les données de va_arg et les transforme si besoin
{
    char	*tmp;

    if (params->type == '%')
		tmp = ft_strdup("%");
	if (params->type == 'c')
		tmp = deal_with_char(tmp, list);
	if (params->type == 's')
		tmp = ft_strdups(va_arg(list, void *));
	if (params->type == 'p')
		tmp = deal_with_pointers(list);
	if (params->type == 'd')
		tmp = ft_itoa(va_arg(list, int));
	if (params->type == 'u')
		tmp = ft_ultoa(va_arg(list, int));
	if (params->type == 'i')
		tmp = ft_itoa(va_arg(list, int));
	if (params->type == 'x')
		tmp = deal_with_hexa(va_arg(list, unsigned int), LOWHEXA);
	if (params->type == 'X')
		tmp = deal_with_hexa(va_arg(list, unsigned int), UPHEXA);

    return (tmp);
}