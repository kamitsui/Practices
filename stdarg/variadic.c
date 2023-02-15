#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	printf_ints(int num, ...)
{
	va_list	args;
	va_start(args, num);

	int	i = 0;
	while (i < num)
	{
		int	value = va_arg(args, int);
		printf("%d: %d\n", i++, value);
	}

	va_end(args);
}

int	main()
{
	printf_ints(3, 24, 42, 321);
	printf_ints(2, 521, 256);
	printf_ints(7, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
	system("leaks a.out");
	return 0;
}
