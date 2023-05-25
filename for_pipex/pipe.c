/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:04:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/24 09:54:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usage pipe()

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int pipefd[2];
	char buffer[256];

	if (pipe(pipefd) == -1) {
		perror("Pipe creation failed");
		return 1;
	}

	pid_t pid = fork();

	if (pid == -1) {
		perror("Fork failed");
		return 1;
	} else if (pid == 0) {
		// Child process
		close(pipefd[1]); // Close the write end of the pipe

		ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer));
		if (bytesRead > 0) {
			printf("Child received: %.*s\n", (int)bytesRead, buffer);
		}

		close(pipefd[0]); // Close the read end of the pipe

		return 0;
	} else {
		// Parent process
		close(pipefd[0]); // Close the read end of the pipe

		const char *message = "Hello from parent";
		ssize_t bytesWritten = write(pipefd[1], message, strlen(message));

		if (bytesWritten > 0) {
		printf("Parent sent: %.*s\n", (int)bytesWritten, message);
		}

		close(pipefd[1]); // Close the write end of the pipe

		wait(NULL); // Wait for the child process to finish

		return 0;
	}
}
//	result of ./a.out                                                                                                                                              ✱
//	Parent sent: Hello from parent
//	Child received: Hello from parent
