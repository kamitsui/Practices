/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:19:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/22 15:54:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Exsample usage dup()

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int originalFd = open("input.txt", O_RDONLY);
	if (originalFd == -1) {
		perror("Error opening file");
		return 1;
	}

	int duplicateFd = dup(originalFd);
	if (duplicateFd == -1) {
		perror("Error duplicating file descriptor");
		close(originalFd);
		return 1;
	}

	char buffer[256];
	ssize_t bytesRead = read(duplicateFd, buffer, sizeof(buffer));
	if (bytesRead == -1) {
		perror("Error reading file");
		close(originalFd);
		close(duplicateFd);
		return 1;
	}

	printf("Read %zd bytes: %.*s\n", bytesRead, (int)bytesRead, buffer);
	// %.*s ... ".*" is field width from argment (int)bytesRead
	// Can be output without null termination

	close(originalFd);
	close(duplicateFd);

	return 0;
}

// result of execute a.out ( from dup.c )
// echo "1234567890" > input.txt
// ./a.out
// Read 11 bytes: 1234567890
