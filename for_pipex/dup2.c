/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:26:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/23 10:59:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Example usage dup2(srcfd, dstfd)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int sourceFd = open("input.txt", O_RDONLY);
//	int sourceFd = open("input.txt", O_RDWR); // this line is not cause of the phenomenon that printf can not do
	if (sourceFd == -1) {
		perror("Error opening file");
		return 1;
	}

	int destinationFd = 1; // STDOUT_FILENO
	//int destinationFd = 7; // FILENO
	if (dup2(sourceFd, destinationFd) == -1) {
		perror("Error duplicating file descriptor");
		close(sourceFd);
		return 1;
	}

	char buffer[256];
	ssize_t bytesRead = read(destinationFd, buffer, sizeof(buffer));
	if (bytesRead == -1) {
		perror("Error reading file");
		close(sourceFd);
		return 1;
	}

//	close(destinationFd); // Cannot write even if this line is added
//	write(STDOUT_FILENO, buffer, bytesRead); // Can not write when destinationFD = 1
	printf("Read %zd bytes: %.*s\n", bytesRead, (int)bytesRead, buffer); // print to input.txt

	close(sourceFd);

	return 0;
}

// input.txt						default
// 1234567890
// input.txt after execute ./a.out	1th
// 1234567890
// Read 11 bytes: 1234567890
//
// input.txt after execute ./a.out	2th
// 1234567890
// Read 11 bytes: 1234567890
//
// Read 38 bytes: 1234567890
// Read 11 bytes: 1234567890
//
//
// input.txt after execute ./a.out	3th
// 1234567890
// Read 11 bytes: 1234567890
// 
// Read 38 bytes: 1234567890
// Read 11 bytes: 1234567890
// 
// 
// Read 92 bytes: 1234567890
// Read 11 bytes: 1234567890
// 
// Read 38 bytes: 1234567890
// Read 11 bytes: 1234567890
// 
// 
// 
