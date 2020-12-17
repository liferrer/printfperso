/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/17 12:55:41 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void    ft_fill(char *s, char c, int nb)
{
    while (nb > 0)
    {
        *s = c;
        s++;
        nb--;
    }
}

char	*ft_prec_apply(char *str, char *tmp, int diff, int value, t_params *params)
{
	if (!(str = (char*)ft_calloc(sizeof(char), (value + 1))))
		return (NULL);
	diff = (value - ft_strlen(tmp));
	ft_fill(str, '0', diff);
	if (params->neg == 1)
	{
		str[0] = '-';
		diff = diff - 1;
	}
	while (*tmp != '\0')
	{
		str[diff] = *tmp;
		diff++;
		tmp++;
	}
	params->tmplen = params->precision;
	return (str);
}