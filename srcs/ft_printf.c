/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liso <liso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/04 13:12:18 by liso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void		display(char *str)
//Affiche la chaîne finale
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

int		copyandsearch(t_params *params, t_flags *flags, char *string, char **result, va_list list) 
//Copie le texte jusqu'au '%', orchestre la récupération des données, génère la chaîne finale
{
	while (*string)
	{
		if (*string == '%')
		{
			string = ft_get_info(params, flags, string, list);
			ft_get_types(params, result, list);
			if (*(string + 1) == '\0')
				return (0);
			string++;			
		}
		*result = ft_strjoinchar(*result, *string, params->len);
		params->len++;
		string++;
	}
	*result = ft_strjoinchar(*result, *string, params->len);
	params->len++;
	return (0);
}

int		ft_printf(const char *string, ...)
//Initialize va_arg, lance le traîtement de données, return la len finale
{
	va_list		list;
	t_params	params;
	t_flags		flags;
	char		*result;

	result = ft_strdup("");
	if (!string)
		return (0);
	ft_memset(&params, 0, sizeof(params));
	va_start(list, string);
	copyandsearch(&params, &flags, (char*)string, &result, list);
	va_end(list);
	display(result);
	return (params.len);
}

int			main(void)
{
	char	*a;
	int		b;
	char	c;
	unsigned int d;

	a = "poisson";
	b = 1;
	c = 'o';
	d = -123456789;
	printf("\nFAKE = return value : %d\n", ft_printf("Je suis %-0450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	printf("\n");
	printf("\nTRUE = return value : %d\n", printf("Je suis %-450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	return (0);
}

// Faire strjoin et tmplen puis voir prec et width !!!!!!