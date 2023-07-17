/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fscanf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:08:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/16 18:13:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	FILE *file = fopen("filename.txt", "r");
	if (file == NULL) {
	    // Handle file open error
	}
	
	int num1, num2;
	char str[100];
	
	int num_items_read = fscanf(file, "%d %d %s", &num1, &num2, str);
	
	if (num_items_read != 3) {
	    // Handle fscanf error or end-of-file condition
		printf("fscanf error\n");
		return 1;
	}

	printf("num1:%d\n", num1);
	printf("num2:%d\n", num2);
	printf("str:%s\n", str);

	fclose(file);
	return 0;
}
