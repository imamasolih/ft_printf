#include <stdio.h>
#include "ft_printf.h"

int  main(void)
{
	int i = 50;


	int ft = ft_printf("Hello %s, value: %d, hex: %x, ptr: %p, percent: %% and final\n","world", 42, 48879, &i);
	int pr = printf("Hello %s, value: %d, hex: %x, ptr: %p, percent: %% and final\n","world", 42, 48879, &i);

	printf("ft_printf returned: %d\n", ft);
	printf("printf returned: %d\n", pr);
	return (0);
}
