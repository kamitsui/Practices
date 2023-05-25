/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:10:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/22 15:14:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Example usage access()

#include <stdio.h>
#include <unistd.h>

int main() {
//	const char *path = "/path/to/file.txt";
	const char *path = "README.md";
	int mode = R_OK;

	int result = access(path, mode);
	if (result == 0) {
		printf("File is readable.\n");
	} else {
		printf("File is not readable or does not exist.\n");
	}

	return 0;
}
