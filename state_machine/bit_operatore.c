#include <stdio.h>
#include "../../Libft/libft/libft.h"
#include <stdlib.h>

int main()
{
	int bit_position = 2;//					 0b0100
	int num = 0x000012;//			0b1010
	printf("%d\t%x\t\t1010\tnum\n", num, num);
	printf("%d\t%x\t\t0100\t(1 << bit_position)\n", (1 << bit_position), (1 << bit_position));
	num |= (1 << bit_position);//	0b1010 | 0b0100
	printf("%d\t%x\t\t1110\tnum |= (1 << bit_position)\n", num, num);//			0b1110
	bit_position = 0;//						 0b0001
	printf("%d\t%x\t\t0001\t(1 << bit_position)\n", (1 << bit_position), (1 << bit_position));
	num |= (1 << bit_position);//	0b1110 | 0b0001
	printf("%d\t%x\t\t1111\tnum |= (1 << bit_position)\n", num, num);//			0b1111
	bit_position = 2;//						 				0b0100
	printf("%d\t%x\t\t0100\t(1 << bit_position)\n", (1 << bit_position), (1 << bit_position));//	0b0000....0100
	printf("%d\t%x     ...1011\t~(1 << bit_position)\timage:%d-%d\n", ~(1 << bit_position), ~(1 << bit_position), num, (1 << bit_position));//	0b1111....1011
	num &= ~(1 << bit_position);//			0
	printf("%d\t%x\t\t1011\tnum &= ~(1 << bit_position)\n", num, num);

	//int r=0;
	int i=0;
	num = 0x10;//0b0001000 position:4
	while(i < 10)
	{
		if ((num >> i) == 1)
			printf("bit_position: %d\t\tnum(%d) >> i(%d)\n", i, num, i);
		i++;
	}

	int value = 5;
	char buff[17] = {0};
	i = 0;
	while (i < 16)
	{
		buff[i] = value & (0x8000 >> i) ? '1' : '0';
		i++;
	}
	printf("%d\t%s\n", value, buff);
	char *binary = ft_itoa_binary(value);
	printf("%d\t%s\tft_itoa_binary(%d)\n", value, binary, value);
	free(binary);
return 0;
}
