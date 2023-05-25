/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:58:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/23 13:52:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usage execve()

#include <unistd.h>
#include <stdio.h>

int main() {
//	const char *filePath = "/bin/ls";
//	char *const arguments[] = { "ls", "-l", NULL };
//	char *const environment[] = { "PATH=/bin:/usr/bin", NULL };
	const char *filePath = "/Users/kamitsui/Documents/42cursus/Practices/process_management/execve_bin";
	char *const arguments[] = { "execve_bin", NULL };
	char *const environment[] = { "PATH=/bin:/usr/bin", NULL };
//	char *const environment[] = { "PATH=/Users/kamitsui/Documents/42cursus/Practices/process_management", NULL };

	int result = execve(filePath, arguments, environment);

	// If execve() returns, an error occurred
	if (result == -1)
		perror("Error executing program");

	return 1;
}
// return of execve()
//		success:	no return
//		fail:		-1
//	result of a.out	: same result of "ls -l"
//		bash-3.2$ ./a.out
//		total 88
//		-rw-r--r--@ 1 kamitsui  2020  1113 May 22 13:06 README.md
//		-rwxr-xr-x  1 kamitsui  2020  8544 May 23 12:04 a.out
//		-rw-r--r--  1 kamitsui  2020  1236 May 22 15:14 access.c
//		-rw-r--r--  1 kamitsui  2020  1803 May 22 15:54 dup.c
//		-rw-r--r--  1 kamitsui  2020  2448 May 23 10:59 dup2.c
//		-rw-r--r--  1 kamitsui  2020  1280 May 23 12:04 execve.c
//		-rw-r--r--  1 kamitsui  2020   200 May 23 10:51 input.txt
//		-rw-r--r--  1 kamitsui  2020  1141 May 22 13:56 perror.c
//		-rw-r--r--  1 kamitsui  2020  1347 May 22 14:17 strerror.c

//	this code is original binary file
//		const char *filePath = "/Users/kamitsui/Documents/42cursus/Practices/process_management/execve_bin";
//		char *const arguments[] = { "execve_bin", NULL };
//		char *const environment[] = { "PATH=/Users/kamitsui/Documents/42cursus/Practices/process_management", NULL };
//	result of original binary file that is called by execve()
//		$ ./a.out
//		binary file for call by ececve()
//		  PID TTY           TIME CMD
//		29317 ttys000    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server /usr/bin/login -fpl kamitsui /Applications/iTerm.app/Contents/MacOS/iTerm2 --launch_shell
//		29319 ttys000    0:02.20 -zsh
//		46624 ttys000    0:00.41 vim execve.c
//		46885 ttys000    0:00.00 execve_bin
//		PATH=/bin:/usr/bin
//		PWD=/Users/kamitsui/Documents/42cursus/Practices/process_management
//		SHLVL=1
//		_=/usr/bin/env
