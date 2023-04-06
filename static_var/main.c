/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:33:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/30 18:34:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	function() {
	static int count = 0;  // declare static variable
	count++;
	printf("Function has been called %d times\n", count);
}

int	main() {
	function();  // prints "Function has been called 1 times"
	function();  // prints "Function has been called 2 times"
	function();  // prints "Function has been called 3 times"
return 0;
}
