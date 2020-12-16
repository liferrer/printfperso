/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <liferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:52 by liferrer          #+#    #+#             */
/*   Updated: 2020/12/16 15:33:01 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int		copyandsearch(t_params *params, t_flags *flags, char *string, char **result, va_list list) 
//Copie le texte jusqu'au '%', orchestre la récupération des données, génère la chaîne finale
{
	while (*string)
	{
		if (*string == '%')
		{
			string = ft_get_info(params, flags, string, list);
			ft_get_types(params, flags, result, list);
			if (*(string + 1) == '\0')
				return (0);
			string++;			
		}
		printf("str=%s= et res=%s= et len=%d=\n", string, *result, params->len);
		*result = ft_strjoinchar(*result, *string, params->len);
		params->len++;
		string++;
	}
	*result = ft_strjoinchar(*result, *string, params->len);
	//params->len++;
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
	write(1, result, params.len);
	free(result);
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
	printf("\nFAKE = return value : %d\n", ft_printf("Je suis un rouge"));
	printf("\n");
	printf("\nTRUE = return value : %d\n", printf("Je suis un rouge"));
	//printf("\nFAKE = return value : %d\n", ft_printf("Je suis %-0450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	//printf("\n");
	//printf("\nTRUE = return value : %d\n", printf("Je suis %-450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	return (0);
}

// Faire strjoin et tmplen puis voir prec et width !!!!!!