/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:53:09 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/16 15:33:17 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *s1, char *s2, int len1, int len2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!(str = (char*)ft_calloc(sizeof(char), (len1 + len2 + 1))))
		return (NULL);
	ft_strncat(str, s1, 0, len1);
	ft_strncat(str, s2, len1, len2);
	return (str);
}
