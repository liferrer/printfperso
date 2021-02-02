/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/02 16:21:07 by liferrer         ###   ########.fr       */
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

char	*ft_prec_apply(char *str, char *tmp, int diff, t_params *params)
{
	if (!(str = (char*)ft_calloc(sizeof(char), (params->precision) + 2)))
		return (NULL);
	
	diff = (params->precision - ft_strlen(tmp));
	ft_fill(str, '0', diff);
	printf(">>> diff = &%d <<<\n", diff);
	if (params->neg == 1)
	{
		str[0] = '-';
	//	diff = diff - 1;
	//printf(">>> tmp = %s <<< \n", tmp);
	}
	while (params->tmplen >= 0)
	{
	printf(">>> tmp = %s <<< \n", tmp);
		str[diff] = *tmp;
		diff++;
		tmp++;
		params->tmplen--;
	}
	params->tmplen = params->precision;
	return (str);
}

char	*ft_precision_apply(char *str, char *tmp, int diff, t_params *params)
{
	char	*start;
	char	*strr;
	int		i;

	strr = NULL;
	i = 0;
	if (!(start = (char*)ft_calloc(sizeof(char), diff + 1)))
		return (NULL);
	
	while (start[i] != '\0')
	{
		start[i] = '0';
		i++;
	}

	strr = ft_strfjoin("-", start, 1, diff);

	start = ft_strfjoin(strr, tmp, ft_strlen(strr, params->tmplen));

	return (start);
}