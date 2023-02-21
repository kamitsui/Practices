#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	printf_pointer(int num, ...)
{
	va_list	ap;
	va_start(ap, num);
	void *	value;
	int i = 0;
	while (i < num)
	{
		value = va_arg(ap, void *);
		printf("%%p: %p\n", value);
		i++;
	}
	va_end(ap);
}

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
	void * p1 = (void *)0x0;
	void * p2 = (void *)0x1;
	int * p_i = (int *)0x2;
	//char *str = (char *)0x7FFFFFFFFFFFFFFF;//64bit LONG_MAX
	char *str = (char *)0xFFFFFFFFFFFFFFFF;//64bit ULONG_MAX
	//char *str = (char *)0x10000000000000000;//over size
	char ch = (char)'a';
	printf_pointer(5, p1, p2, p_i, str, &ch);
	//size_t d = str;
	printf("%lx\n", (unsigned long)str);
	printf("%zx\n", (size_t)str);
//	system("leaks a.out");
	return 0;
}
