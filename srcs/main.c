#include "../lib/libft.h"

int			main(void)
{

char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

	ft_printf("\nFAKE = return value : |%d|\n", ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));
	
	printf("\nTRUE = return value : |%d|\n", printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));
	// printf("\nFAKE = return value : %d\n", ft_printf("Je suis %-0450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	// printf("\n");
	// printf("\nTRUE = return value : %d\n", printf("Je suis %-450.4d %s rouge et je suis dans l'%c, %x et voici un pointeur : %p, et voici un UL : %.15u", b, a, c, 2000, &a, d));
	return (0);
}