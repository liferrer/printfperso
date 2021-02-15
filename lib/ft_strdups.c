/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:41:37 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/15 11:17:11 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdups(const char *s)
{
	size_t	slen;
	size_t	i;
	char	*res;

	if (s == NULL)
	{
		res = ft_strdup("(null)");
		return (res);
	}
	slen = ft_strlen(s);
	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * slen + 1)))
		return (0);
	while (i < slen)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
