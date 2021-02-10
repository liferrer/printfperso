/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/10 12:21:07 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_minus(t_prm *prm, char *string)
{
	prm->minus = 1;
	string++;
}

void	ft_zero(t_prm *prm, char *string)
{
	prm->zero = 1;
	string++;
}

long	ft_get_size(unsigned long nb, int base)
{
	int i;

	i = 1;
	while (nb >= (unsigned long)base)
	{
		nb /= (unsigned long)base;
		i++;
	}
	return (i);
}
