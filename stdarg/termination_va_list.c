/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination_va_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:30:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/10 14:30:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	va_function(int num, ...)
{
	va_list	ap;
	int		result;
	int		i;

	va_start(ap, num);
	i = 0;
	while (i < num)
	{
		result = va_arg(ap, int);
		printf("%d,", result);
		i++;
	}
	result = va_arg(ap, int);
	if (*ap == '\0')
		printf("*ap == null_terminal\n");
	va_end(ap);
}

int	main(void)
{
	va_function(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 42);
	return 0;
}
