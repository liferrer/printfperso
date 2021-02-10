/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/10 12:22:32 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_flag_zero(char *tmp, char *str, int diff)
{
	while (diff != 0)
	{
		*str = '0';
		diff--;
		str++;
	}
	while (*tmp != '\0')
	{
		*str = *tmp;
		str++;
		tmp++;
	}
}

void	ft_flag_minus(char *tmp, char *str, int diff, t_prm *prm)
{
	if (prm->neg == 1)
	{
		*str = '-';
		str++;
		prm->neg = 0;
	}
	while (prm->tmplen > 0)
	{
		*str = *tmp;
		str++;
		tmp++;
		prm->tmplen--;
	}
	while (diff > 0)
	{
		*str = ' ';
		diff--;
		str++;
	}
}

void	ft_no_flag(char *tmp, char *str, int diff, t_prm *prm)
{
	while (diff != 0)
	{
		*str = ' ';
		diff--;
		str++;
	}
	while (*tmp != '\0')
	{
		if (prm->neg == 1)
		{
			*str = '-';
			prm->neg = 0;
			str++;
		}
		*str = *tmp;
		str++;
		tmp++;
	}
}
