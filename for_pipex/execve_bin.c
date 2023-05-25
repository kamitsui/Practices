/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:58:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/05/23 13:47:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// binary file for call by execve()

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("binary file for call by ececve()\n");
	system("ps");
	system("env");
	return 0;
}
