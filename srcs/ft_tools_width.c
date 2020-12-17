/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/17 13:21:26 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_flag_zero(char *tmp, char *str, int diff)
{
	printf("caca");
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

void	ft_flag_minus(char *tmp, char *str, int diff)
{
	while (*tmp != '\0')
	{
		*str = *tmp;
		str++;
		tmp++;
	}
	while (diff != 0)
	{
		*str = ' ';
		diff--;
		str++;
	}
}

void	ft_no_flag(char *tmp, char *str, int diff)
{
	while (diff != 0)
	{
		*str = ' ';
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