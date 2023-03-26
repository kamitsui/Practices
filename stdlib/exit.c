/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:03:47 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/26 17:07:46 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	call_exit(void)
{
	exit(1);
}

int	main(void)
{
	printf("before status\n");
	system("echo $?");
	call_exit();
	//not executed the below
	printf("after status\n");
	system("echo $?");
	return (0);
}
