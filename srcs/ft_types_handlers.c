/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/10 15:35:33 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char		*deal_with_hexa(unsigned long nb, char *base)
{
	char		*str;
	int			i;

	i = ft_get_size(nb, 16) - 1;
	if (!(str = malloc(sizeof(char) * (ft_get_size(nb, 16) + 1))))
		return (NULL);
	str[ft_get_size(nb, 16)] = '\0';
	while (nb >= 0 && i >= 0)
	{
		str[i] = base[nb % 16];
		nb /= 16;
		i--;
	}
	return (str);
}

char		*deal_with_pointers(va_list list)
{
	char			*hexanum;
	char			*result;
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(list, void*);
	if (!ptr)
		return (result = ft_strdup("0x0"));
	hexanum = deal_with_hexa(ptr, LOWHEXA);
	result = ft_strnjoin("0x", hexanum, 2, ft_strlen(hexanum));
	return (result);
}

char		*deal_with_char(char *tmp, va_list list)
{
	if (!(tmp = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	tmp[0] = va_arg(list, int);
	tmp[1] = '\0';
	return (tmp);
}

char		*deal_with_type(t_prm *prm, va_list list)
{
	char		*tmp;

	if (prm->type == '%')
		tmp = ft_strdup("%");
	if (prm->type == 'c')
		tmp = deal_with_char(tmp, list);
	if (prm->type == 's')
		tmp = ft_strdups(va_arg(list, void *));
	if (prm->type == 'p')
		tmp = deal_with_pointers(list);
	if (prm->type == 'd')
		tmp = ft_itoa(va_arg(list, int), prm);
	if (prm->type == 'u')
		tmp = ft_ultoa(va_arg(list, int));
	if (prm->type == 'i')
		tmp = ft_itoa(va_arg(list, int), prm);
	if (prm->type == 'x')
		tmp = deal_with_hexa(va_arg(list, unsigned int), LOWHEXA);
	if (prm->type == 'X')
		tmp = deal_with_hexa(va_arg(list, unsigned int), UPHEXA);
	return (tmp);
}
