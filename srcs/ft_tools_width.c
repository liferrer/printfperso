/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/16 15:33:16 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char    *ft_flag_zero(char *tmp, char *str, int diff)
{
	while (*tmp != '\0')
	{
		str[diff] = *tmp;
		diff++;
		tmp++;
	}
    return (str);
}

char    *ft_flag_minus(char *tmp, char *str, int diff)
{
	while (*tmp != '\0')
	{
		*str = *tmp;
		str++;
		tmp++;
		diff--;
	}
	while (diff)
	{
		*str = ' ';
		diff--;
		str++;
	}
    return (str);
}