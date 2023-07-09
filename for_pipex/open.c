/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:17 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/13 19:11:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	main(void)
{
	int	result;
	int	error_number;
	char	*error_message;
	char	*path = "file";
	result = access(path, F_OK);
	if (result == -1)
	{
		error_number = errno;
		error_message = strerror(error_number);
		printf("bash: %s: %s\n", path, error_message);
		exit (1);
	}
//	if (open("file", O_RDONLY) == -1)
//		printf("open ng!\n");
	return 0;
}
