/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_restart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:29:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/26 15:29:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sig_handler(int signo) {
    if (signo == SIGUSR1) {
        printf("Received SIGUSR1 signal. Continuing interrupted system call.\n");
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sa.sa_flags = SA_RESTART; // Set SA_RESTART flag

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Try to read from stdin
        printf("Waiting for input...\n");
        char buffer[256];
        ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));

        if (bytes_read == -1) {
            if (errno == EINTR) {
                // read() was interrupted by a signal, but will automatically resume
                // with SA_RESTART flag set
                continue;
            } else {
                perror("read");
                exit(EXIT_FAILURE);
            }
        }

        // Process the input
        printf("Read %zd bytes: %s\n", bytes_read, buffer);
    }

    return 0;
}
