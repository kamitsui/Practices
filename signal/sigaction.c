/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:01:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/25 12:31:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum) {
    printf("\tSignal %d received\n", signum);
    // Handle the signal here
}

int main() {
    // Define the action structure
    struct sigaction sa;
    sa.sa_handler = handler; // Set the custom handler function
    sigemptyset(&sa.sa_mask); // Clear the signal mask
    sa.sa_flags = 0; // No special flags

    // Register the handler function for SIGINT (Ctrl+C) signal
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to keep the program running
    while (1) {
        // Your program logic here
    }

    return 0;
}
