#include <stdio.h>

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
	printf("%d\t%x\t1011\t~(1 << bit_position)\timage:%d-%d\n", ~(1 << bit_position), ~(1 << bit_position), num, (1 << bit_position));//	0b1111....1011
	num &= ~(1 << bit_position);//			0
	printf("%d\t%x\t\txxxx\tnum &= ~(1 << bit_position)\n", num, num);
return 0;
}
