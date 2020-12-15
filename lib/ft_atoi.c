/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:07:45 by liferrer          #+#    #+#             */
/*   Updated: 2020/01/08 16:20:30 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	int				ng;
	long long int			nb;

	i = 0;
	ng = 1;
	nb = 0;
	if (ft_memcmp("", str, 1) == 0)
		return (0);
	while (ft_strchr("\n\t\r\v\f ", str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		ng = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * ng);
}