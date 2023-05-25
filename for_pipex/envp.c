/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:37:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/24 13:51:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usage **envp

#include <stdio.h>

int	main(int ac, char **av, char **ep)
{
	int	i = 0;
	while (ep[i] != NULL)
	{
		printf("%s\n", ep[i]);
		i++;
	}
	ac++;
	printf("\n**av:%p\n", av);
	return 0;
}
