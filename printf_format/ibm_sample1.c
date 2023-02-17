#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
    char ch = 'h', *string = "computer";
    int count = 234, hex = 0x10, oct = 010, dec = 10;
    double fp = 251.7366;
    wchar_t wc = (wchar_t)0x0058;
    wchar_t ws[4];

    printf("1234567890123%n4567890123456789\t1234567890123%%n4567890123456789 -> &count\n\n", &count);
    printf("Value of count should be 13; count = %d\n\n", count);
    printf("%10c%5c\t\t%%10c%%5c <- 'h'\n", ch, ch);
	//printf("%.3c\n", ch);
	//printf("%.3p\n", string);
	//printf("%p\n", string);
    printf("%25s\t\t%%25s <- \"computer\"\n", string);
	printf("%25.4s\t\t%%25.4s <- \"computer\"\n", string);
    printf("%f    %.2f    %e    %E\n\n", fp, fp, fp, fp);
    printf("%i    %i     %i\n\n", hex, oct, dec);
}
