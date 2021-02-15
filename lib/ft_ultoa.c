/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:10:55 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 11:23:20 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(int n)
{
	int				i;
	unsigned int	nb;
	int				size;
	char			*str;

	if (n < 0)
		nb = 4294967296 + n;
	else
		nb = n;
	i = ft_get_size(nb, 10) - 1;
	size = ft_get_size(nb, 10);
	if (!(str = (char *)ft_calloc(sizeof(char), (size + 1))))
		return (NULL);
	while (i >= 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
