/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:02:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/23 19:30:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usage fork()

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t childPid = fork();

	if (childPid == -1) {
		perror("Fork failed");
		return 1;
	} else if (childPid == 0) {
		// Child process
		printf("Hello from child process! (PID: %d)\n", getpid());
		system("ps"); // slow behavior than Parent process, same the "ps" is called by ParentProcess.
	} else {
		// Parent process
		printf("Hello from parent process! (PID: %d, Child PID: %d)\n", getpid(), childPid);
		system("ps");
	}

	return 0;
}

//	result of executed a.out
//	./a.out
//	Hello from parent process! (PID: 22526, Child PID: 22527)
//	Hello from child process! (PID: 22527)
//	  PID TTY           TIME CMD
//	  PID TTY           TIME CMD
//	 1766 ttys000    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server /usr/bin/login -fpl kamitsui /Applications/iTerm.app/Contents/MacOS/iTerm2 --launch_shell
//	 1766 ttys000    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server /usr/bin/login -fpl kamitsui /Applications/iTerm.app/Contents/MacOS/iTerm2 --launch_shell
//	 1769 ttys000    0:00.55 -zsh
//	 1769 ttys000    0:00.55 -zsh
//	16144 ttys000    0:00.45 vim fork.c
//	16144 ttys000    0:00.45 vim fork.c
//	23039 ttys000    0:00.00 ./a.out
//	23039 ttys000    0:00.00 ./a.out
//	23040 ttys000    0:00.00 ./a.out
//	23040 ttys000    0:00.00 ./a.out
