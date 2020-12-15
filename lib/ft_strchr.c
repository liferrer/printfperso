/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:03:22 by liferrer          #+#    #+#             */
/*   Updated: 2018/11/30 12:22:36 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	if (c == 0)
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (i--)
				str++;
			return (str);
		}
		i++;
	}
	return (NULL);
}
