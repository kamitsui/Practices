/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:09:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/10 19:14:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        sleep(5);
        exit(42);  // Exit with a status of 42
    } else {
        // Parent process
        printf("Parent process: PID = %d getpid()\n", getpid());

        // Wait for the child process to terminate
        pid_t terminated_pid = waitpid(pid, &status, 0);

        if (terminated_pid == -1) {
            perror("waitpid");
            exit(1);
        }

        if (WIFEXITED(status)) {
            // Child process exited normally
            int exit_status = WEXITSTATUS(status);
            printf("Child process %d exited with status: %d\n", terminated_pid, exit_status);
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            int signal_number = WTERMSIG(status);
            printf("Child process %d terminated by signal: %d\n", terminated_pid, signal_number);
        }
    }

    return 0;
}
