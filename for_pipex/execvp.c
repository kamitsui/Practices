/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:30:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/08 17:36:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	// Create an array of command-line arguments
	//char *const argv[] = { "ls", "-l", NULL };
	char *const argv[] = { "ls", "-al", NULL };// "ls -al"

	// Execute the "ls -l" command
	execvp("ls", argv);

	// If execvp returne, it means an error occurred
	perror("execvp");
	return 1;
}
