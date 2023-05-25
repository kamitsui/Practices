/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:34:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/24 09:39:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usage wait()

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	pid_t childPid = fork();
	pid_t currentPid = getpid();

	if (childPid == -1) {
		perror("Fork failed");
		return 1;
	} else if (childPid == 0) {
		// Child process
		printf("Child process executing! (PID: %d)\n", currentPid);
		sleep(3); // Simulate some work in the child process
		return 42; // Child process exits with status 42
//		NG code ... freeze
//		if (kill(currentPid, SIGSTOP) == -1)
//			return 42; // Child process exits with status 42
//		printf("Process stopped successfully.\n");
//		return 0;
	} else {
		// Parent process
		printf("Parent process waiting for child to terminate...\n");
		int status;
		pid_t terminatedChildPid = wait(&status);

		if (terminatedChildPid == -1) {
			perror("Wait failed");
			return 1;
		}

		if (WIFEXITED(status)) {
			printf("Child process terminated normally. Exit status: %d\n", WEXITSTATUS(status));
		} else if (WIFSIGNALED(status)) {
			printf("Child process terminated by signal. Signal number: %d\n", WTERMSIG(status));
		}
	}

	return 0;
}

//	result of ./a.out
//	Parent process waiting for child to terminate...
//	Child process executing! (PID: 75844)
//	Child process terminated normally. Exit status: 42 // display this line after a few second.
