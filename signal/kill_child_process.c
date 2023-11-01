/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:28:33 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/25 18:37:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID: %d) is running.\n", getpid());
        
        // Child process does some work...
        //sleep(10);
		int	signum;
		while (1)
		{
			scanf("%d", &signum);
			printf("signum [%d]\n", signum);
		}
        
        printf("Child process terminating.\n");
        exit(EXIT_SUCCESS);
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d) is waiting for the child process (PID: %d) to finish.\n", getpid(), child_pid);
        
        // Wait for the child process to finish
        int status;
        waitpid(child_pid, &status, 0);

		if (WIFEXITED(status))
		{
			printf("child process was exited\n");
			status = WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			printf("child process was signaled\n");
			status = WTERMSIG(status);
		}
		printf("Exit Status of children process ... [%d]\n", status);
        // Send a SIGTERM signal to the child process
        if (kill(child_pid, SIGTERM) == -1) {
            perror("kill");
        }

        printf("Parent process terminating.\n");
    }

    return 0;
}
