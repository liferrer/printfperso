/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liso <liso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/04 11:11:09 by liso             ###   ########.fr       */
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
		*str = 0;
		diff--;
		str++;
	}
    return (str);
}