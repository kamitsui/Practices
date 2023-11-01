/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:15:54 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/26 15:16:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo, siginfo_t *info, void *context) {
    printf("Received signal: %d\n", signo);
    printf("Additional information: si_pid=%d, si_uid=%d\n", info->si_pid, info->si_uid);
	(void)context;
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO | SA_RESTART; // Set SA_SIGINFO and SA_RESTART flags
    sa.sa_sigaction = sig_handler;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Sending SIGUSR1 signal...\n");
    kill(getpid(), SIGUSR1); // Send SIGUSR1 signal to the current process

    // Sleep for a while to allow the signal handler to execute
    sleep(1);

    printf("Signal sent and handled.\n");

    return 0;
}
