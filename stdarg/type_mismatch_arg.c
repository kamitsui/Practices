/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_mismatch_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:07:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/10 20:16:28 by kamitsui         ###   ########.fr       */
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
	while (i < num - 1)
	{
		result = va_arg(ap, int);
		printf("%d,", result);
		i++;
	}
	long	l;
	l = va_arg(ap, long);
	printf("%ld\n", l);
	va_end(ap);
}

int	main(void)
{
	va_function(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 42);
	return 0;
}
