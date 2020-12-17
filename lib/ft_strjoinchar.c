/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:53:09 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/17 11:48:24 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinchar(char *s1, char c, int len)
{
	char	*str;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';

	str = ft_strnjoin(s1, tmp, len, 2);
	if (s1)
		free(s1);
	return (str);
}