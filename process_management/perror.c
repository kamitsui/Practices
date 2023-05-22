/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:36:38 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/22 13:56:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Example usage of perror()

#include <stdio.h>
//#include <errno.h>

int	main()
{
	FILE *file = fopen("nonexistent_file", "r");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}
	// File operations...
	fclose(file);
	return 0;
}
