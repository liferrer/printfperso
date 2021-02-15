/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:25:58 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 11:14:59 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = ((unsigned char*)s1);
	str2 = ((unsigned char*)s2);
	while (n-- > 0)
	{
		if (!(*str1 == *str2))
			return ((int)(*str1 - *str2));
		str1++;
		str2++;
	}
	return (0);
}
