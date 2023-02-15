#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	my_printf(const char *format, ...)
{
	va_list	args;
	int	done;

	va_start(args, format);
	done = vfprintf(stdout, format, args);
//	done = vfprintf(stdout, format, args);
	va_end(args);
	return (done);
}

int	main(void)
{
	my_printf("Something we don't want to say.\n");
	my_printf("Jacob says, \"Hello World\"\n");
	my_printf("---- %%d ----\n");
	my_printf("---- %! ----\n");
	my_printf("---- %\" ----\n");
	my_printf("---- %c ----\n");
	my_printf("---- %s ----\n");
	my_printf("---- %d ----\n");
	my_printf("---- %i ----\n");
	my_printf("---- %u ----\n");
	my_printf("---- %x ----\n");
	my_printf("---- %X ----\n");
	//printf("%c\n");//compile error : more '%' conversions than data arguments
//	my_printf("---- %" ----\n");//conpile error
	return 0;
}
