/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/22 14:17:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Example usage of strerror()

#include <stdio.h>
#include <string.h>
#include <errno.h>

int	main(void)
{
	FILE *file = fopen("nonexistent_file.txt", "r");
	if (file == NULL) {
		int	errorNumber = ENOENT; // No such file or directory
		//int	errorNumber = errono; // Capture the current value of errno
		char	*errorMessage = strerror(errorNumber);
		printf("Error: %s\n", errorMessage);
		return 1;
	}
	// File operations...
	fclose(file);
	return 0;
}
