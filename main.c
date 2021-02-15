#include "../lib/libft.h"

int			main(void)
{
	ft_printf("\nFAKE = return value : |%d|\n", ft_printf("%% *.5i 42 == |% *.5i|\n", 4, -42));
	
	printf("\nTRUE = return value : |%d|\n", printf("%% *.5i 42 == |% *.5i|\n", 4, -42));
	// printf("\nFAKE = return value : %d\n", ft_printf("Je suis %-0450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	// printf("\n");
	// printf("\nTRUE = return value : %d\n", printf("Je suis %-450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	return (0);
}