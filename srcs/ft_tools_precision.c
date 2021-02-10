/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/10 15:34:48 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_fill(char *s, char c, int nb)
{
	while (nb > 0)
	{
		*s = c;
		s++;
		nb--;
	}
}

char	*ft_prec_apply(char *str, char *tmp, int diff, t_prm *prm)
{
	char	*start;
	char	*strr;
	int		i;

	strr = ft_strdup("");
	str = ft_strdup("");
	i = 0;
	diff = (prm->precision - ft_strlen(tmp));
	if (!(start = (char*)ft_calloc(sizeof(char), diff + 1)))
		return (NULL);
	start[diff] = '\0';
	ft_fill(start, '0', diff);
	if (prm->neg == 1)
	{
		strr = ft_strnjoin("-", start, 1, ft_strlen(start));
		str = ft_strnjoin(strr, tmp, ft_strlen(strr), prm->tmplen);
	}
	else
		str = ft_strnjoin(start, tmp, ft_strlen(start), prm->tmplen);
	prm->tmplen = prm->precision + prm->neg;
	prm->neg = 0;
	return (str);
}
