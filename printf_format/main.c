#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// struct tm
// {
// 	int	tm_sec;
// 	int	tm_;
// 	int	tm_;
// 	int	tm_;
// }


int	main(void)
{
	int		d = 12345;
	float	f = 123.45;
	printf("%09d\n", d);
	printf("%09.3f\n", f);

	printf("---- int ----\n");
	int	d1 = -2147483648;//	INT_MIN
	int	d2 = 2147483647;//	INT_MAX
	printf("%%d\t%d\t~\t%d\n", d1, d2);

	printf("---- unsigned int ----\n");
	unsigned int	u1 = 0U;
	unsigned int	u2 = 4294967295U;//	UINT_MAX
	printf("%%u\t%u\t~\t%u\n", u1, u2);

	printf("---- long int ----\n");
	long int	ld1 = -9223372036854775807L-1;//	LONG_MIN
	long int	ld2 = 9223372036854775807L;//	LONG_MAX
	printf("%%ld\t%ld\t~\t%ld\n", ld1, ld2);

	printf("---- long long int ----\n");
	long long int	lld1 = -9223372036854775807LL-1;//	LLONG_MIN
	long long int	lld2 = 9223372036854775807LL;//		LLONG_MAX
	printf("%%lld\t%lld\t~\t%lld\n", lld1, lld2);

	printf("---- unsigned long int ----\n");
	unsigned long int	lu1 = 0UL;
	unsigned long int	lu2 = 18446744073709551615UL;//		ULONG_MAX
	printf("%%lu\t%lu\t~\t%lu\n", lu1, lu2);

	printf("---- flag - ----\n");
	printf("|%10d|\t%%10d\n", 12345);
	printf("|%-10d|\t%%-10d\n", 12345);
	printf("|%10i|\t%%10i\n", 12345);
	printf("|%-10i|\t%%-10i\n", 12345);
	printf("|%10s|\t%%10s\n", "Hello");
	printf("|%-10s|\t%%-10s\n", "Hello");
	printf("|%-10c|\t%%-10c\n", 'a');
	printf("|%10c|\t%%10c\n", 'a');
	printf("|%-10p|\t%%10p\n", (void *)0);
	printf("|%10p|\t%%10p\n", (void *)0);
	printf("|%-3d|\t%%-3d\n", 12345);
	printf("|%-10s|\t%%-10s\n", "Hello, World");
	printf("|%-10p|\t%%10p\n", (void *)0x3456789012);
	printf("---- flag .n precision ----\n");
	printf("|%.4f|\t%%.4f <- 3.14159\n", atof("3.14159"));
	printf("|%.3d|\t%%.3d\n", 12345);
	printf("|%.10d|\t%%.10d\n", 12345);
	printf("|%0.10d|\t%%0.10d\n", 12345);
	printf("|% .10d|\t%% .10d\n", 12345);
	printf("|% .10d|\t%% .10d\n", -12345);
	printf("---- Two or more flags of the same ----\n");
	printf("|%  .10d|\t%%  .10d\n", 12345);
	printf("|%--10s|\t%%--10s\n", "Hello");
	printf("---- flag width ----\n");
	printf("|%10s|\t%%10s\n", "Hello");
	printf("|%10s|\t%%10s\n", "Hello, World");
	printf("---- flag  ----\n");
	printf("|%010d|\t%%010d\n", 12345);
	printf("|%+d|\t%%+d\n", 12345);
	printf("|%+d|\t%%+d\n", -12345);
	printf("|%10d|\t%%10d\n", 12345);
	printf("|%.10d|\t%%.10d\n", 12345);
	printf("|%010d|\t%%010d\n", 12345);
	printf("|% 10d|\t%% 10d\n", 12345);
	printf("|% 6.2f|\t%% 6.2f\n", 12345.006);
	//printf("|% 6.2d|\t%% 6.2d\n", 12345.00001);
	printf("|%+ 10d|\t%%+ 10d\twarning: flag ' ' is ignored when flag '+' is present\n", 12345);
	printf("|%+ 4d|\t%%+ 4d\twarning: flag ' ' is ignored when flag '+' is present\n", 12345);
	printf("|%+ 5d|\t%%+ 5d\twarning: flag ' ' is ignored when flag '+' is present\n", 12345);
	printf("|%+ 6d|\t%%+ 6d\twarning: flag ' ' is ignored when flag '+' is present\n", 12345);
	printf("|%+ 10d|\t%%+ 10d\twarning: flag ' ' is ignored when flag '+' is present\n", -12345);
	printf("|%+ 5d|\t%%+ 5d\twarning: flag ' ' is ignored when flag '+' is present\n", -12345);
	printf("|%d|\t\t%%d\n", 12345);
	printf("|%o|\t\t%%o\n", 012345);
	printf("|%#o|\t%%#o\n", 012345);
	printf("---- flag time ----\n");
	printf("---- other ----\n");
	printf("asdfgh%");
	printf("\nasddd%basdfg");
	//printf("%1$d:%2$.*3$d:%4$.*3$d\n", HH, min, precision, sec);
	return 0;
}
