/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:12:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/30 12:36:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include "readline/readline.h"
//#include "readline/history.h"

int main() {
    char *input;

    // Enable Readline history
    using_history();

    while (1) {
        input = readline("Enter a command: ");

        if (!input)
            break;

        if (input[0] != '\0') {
            // Add non-empty input to history
            add_history(input);

            // Replace the current input line with a new text
            rl_replace_line("You entered: Custom Text", 1);
            // Move the cursor to the end of the line
            rl_point = rl_end;

            // Print the replaced line
            rl_redisplay();

            // Add a newline after the replaced line
            putchar('\n');
        }

        free(input);
    }

    return 0;
}
