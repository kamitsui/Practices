#include <stdio.h>
#include <unistd.h>
#include "../../Libft/libft/libft.h"
#include "main.h"

int		error(char *input, t_state_machine *machine)
{
	////////// DO ERROR CONV
	printf("cur = '%c' | state = ERROR\n", *input);
	machine->state = LETTER;
	machine->flag = 0;
	return (1);
}

int		conv(char *input, t_state_machine *machine)
{
	static char	*str_conv = ALLCONV;
	int			i;
	
	i = 0;
	while (i < NB_CONV)
	{
		if (ft_strnequ(input, str_conv + i, 1) == TRUE)
		{
			machine->flag |= (1 << i) << 8;
			printf("cur = '%c' | state = CONV \t| flag = %s (%d)\n", *input, ft_itoa_binary(machine->flag), machine->flag);
			////////// DO CONV
			do_conversion(machine);
			machine->state = LETTER;
			machine->flag = 0;
			return (1);
		}
		i++;
	}
	machine->state = ERROR;
	return (0);
}

int		flag(char *input, t_state_machine *machine)
{
	static char	*str_flag[NB_FLAG] = {FLAG_HH, FLAG_LL, FLAG_H, FLAG_L, FLAG_ZERO, FLAG_HASH, FLAG_SPACE};
	int		i;
	int		size;
	
	i = 0;
	while (i < NB_FLAG)
	{
		size = i < 2 ? 2 : 1;
		if (ft_strnequ(input, str_flag[i], size) == TRUE)
		{
			machine->flag |= (1 << i);
			printf("cur = '%s' | state = FLAG \t| flag = %s (%d)\n", str_flag[i], ft_itoa_binary(machine->flag), machine->flag);
			return (size);
		}
		i++;
	}
	machine->state = CONV;
	return (0);
}


void	add_to_buff(char c, t_state_machine *machine)
{
	if (machine->len == 4096)
	{
		//ft_strjoin_free(out, machine->buffer);
		bzero(&machine->buffer, 4096);
		machine->len = 0;
	}
	machine->buffer[machine->len] = c;
	machine->len++;
}

int		letter(char *input, t_state_machine *machine)
{
	if (*input == '%')
		machine->state = FLAG;
	else
	{
		add_to_buff(*input, machine);
		printf("cur = '%c' | state = LETTER\n", *input);
	}
	return (1);
}

void	ft_printf(char *input, ...)
{
	static t_function process[4] = {letter, flag, conv, error};
	t_state_machine machine;
	va_list	ap;
	int		ret;

	va_start(input, ap);
	machine.state = LETTER;
	machine.len = 0;
	machine.flag = 0;
	bzero(&machine.buffer, 4096);
	while (input != NULL && *input != '\0')
	{
		if ((ret = process[machine.state](input, &machine)) >= 0)
			input += ret;
	}
	//ft_strjoin_free(out, machine->buffer);
	//write(1, out, size);
	//free(out);
	va_end(ap);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (EXIT_FAILURE);
	ft_printf(av[1]);	
	return (EXIT_SUCCESS);
}
