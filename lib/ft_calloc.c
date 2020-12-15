/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:27:16 by liferrer          #+#    #+#             */
/*   Updated: 2020/01/06 16:15:00 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	void			*tab;

	i = count * size;
	if (!(tab = malloc(i)))
		return (NULL);
	ft_memset(tab, 0, i);
	return (tab);
}
