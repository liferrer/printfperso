/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liso <liso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:10:55 by liferrer          #+#    #+#             */
/*   Updated: 2021/01/12 13:37:52 by liso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_length(int n)
{
	int i;

	i = 1;
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = n < 0 ? 1 : 0;
	n = j == 1 ? n * -1 : n;
	i = ft_length(n) - 1 + j + 1;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (n > 0)
	{
		str[--i] = ((n % 10) + 48);
		n = n / 10;
	}
	if (j == 1)
	{
		str[0] = '-';
		params->neg = 1;
	}
	return (str);
}
