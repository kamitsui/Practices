/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:50:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/10 16:51:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int main() {
    char *input = readline("Enter something: ");
    if (input) {
        printf("You entered: %s\n", input);
        free(input); // Free the allocated memory
    }
    return 0;
}

