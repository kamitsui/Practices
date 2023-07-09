/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:14:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/26 10:31:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

// Usage strtok()
int	main(void)
{
	char	str[] = ",Hello,World,OpenAI";
	const char	*delimiters = ",";

	// Tokenize the string using strok
	char	*token = strtok(str, delimiters);

	// Loop through the tokens until no more tokens are found
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delimiters);
	}
	return 0;
}
