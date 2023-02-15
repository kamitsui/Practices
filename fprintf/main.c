#include <stdio.h>

int	main()
{
	FILE	*file = fopen("out.txt", "w");
	if (file == NULL)
	{
		printf("Error : can not open file\n");
		return 1;
	}
	fprintf(file, "hello world %d", 4242);
	fclose(file);



	return 0;
}
