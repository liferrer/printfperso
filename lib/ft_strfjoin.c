/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:53:09 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 11:15:59 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfjoin(char *s1, char *s2, int len1, int len2)
{
	char	*str;

	str = ft_strnjoin(s1, s2, len1, len2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
