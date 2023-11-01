/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigterm_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:33:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/25 23:06:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int	g_signum;

// Signal handler for SIGINT (Ctrl + C)
void sigint_handler(int g_signum) {
    printf("Received SIGINT signal (Ctrl + C) ... (%d)\n", g_signum);
    // Handle SIGINT...
	//exit(0x80 | signum);// 130 = 128 + 2
}

// Signal handler for SIGTERM
void sigterm_handler(int g_signum) {
    printf("Received SIGTERM signal ... (%d)\n", g_signum);
    // Handle SIGTERM...
	//exit(signum);// SIGTERM = 15
	//exit(0x80 | SIGINT);// 130 = 128 + 2
    //exit(EXIT_FAILURE); // Terminate the process with a failure status : 1
						// But when if send Ctl + C, return 130
}

int main() {

    printf("Process running. PID: %d\n", getpid());
    printf("Waiting for signals...\n");

	int	status;
	pid_t	pid;
	pid = fork();
	if (pid == 0)
	{

	int	g_signum;

        // Set up SIGINT handler
        struct sigaction sa_int;
        sa_int.sa_handler = sigint_handler;
        sigemptyset(&sa_int.sa_mask);
        sa_int.sa_flags = 0;
        //sigaction(SIGINT, &sa_int, NULL);
        // Register the SIGINT signal handler using sigaction
        if (sigaction(SIGTERM, &sa_int, NULL) == -1) {
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        // Set up SIGTERM handler
        struct sigaction sa_term;
        sa_term.sa_handler = sigterm_handler;
        sigemptyset(&sa_term.sa_mask);
        sa_term.sa_flags = 0;
        //sigaction(SIGTERM, &sa_term, NULL);
        // Register the SIGTERM signal handler using sigaction
        if (sigaction(SIGTERM, &sa_term, NULL) == -1) {
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

		printf("Child Process running. PID: %d\n", getpid());
		// Keep the program running
		while(1)
		{
			pid_t	child_pid;
			child_pid = getpid();
			// Do some work...
			printf("scanf ... signum? ");
			scanf("%d", &g_signum);
			printf("signum = [%d]\n", g_signum);
			if (g_signum == 1)
				if (kill(child_pid, SIGINT) == -1)
					perror("kill");
		}
	}
	else
	{
		waitpid(pid, &status, 0);
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
	}
	return (status);
}
