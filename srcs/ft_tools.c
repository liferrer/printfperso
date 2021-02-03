/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2021/02/03 16:09:23 by liferrer         ###   ########.fr       */
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
	flags->zero = 1;
	string++;
}

long	ft_get_size(unsigned long nb, int base)
{
    int i;

    i = 1;
    while (nb > (unsigned long)base)
    {
        nb /= (unsigned long)base;
        i++;
    }
    return (i);
}