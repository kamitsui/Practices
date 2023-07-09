/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:03:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/08 16:04:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Void : Inplement getenv()
//int	main(int ac, char **av, char **env)
//{
//	if (av[ac] == "")
//	{
//
//	}
//	return 0;
//}

// Usage getenv()
int	main(void)
{
	char	*path = getenv("PATH");
	if (path != NULL)
		printf("PATH:%s\n", path);
	else
		printf("PATH: not found\n");
	return 0;
}
