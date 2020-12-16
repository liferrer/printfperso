/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/16 15:33:16 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

//Petites fonctions utiles à la fonction get_info
void    ft_minus(t_flags *flags, char *string)
{
	flags->minus = 1;
	string++;
}

void    ft_zero(t_flags *flags, char *string)
{
	if (flags->minus == 0)
		flags->zero = 1;
	string++;
}

long	ft_get_size(unsigned long nb)
{
    int i;

    i = 1;
    while (nb > 16)
    {
        nb /= 16;
        i++;
    }
    return (i);
}