/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:29:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/11 20:30:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIN_WIDTH 800  // Width of the window
#define WIN_HEIGHT 600 // Height of the window
#define NUM_CIRCLES 10 // Number of circles to display


int main()
{
    void *mlx_ptr;      // MiniLibX graphics system pointer
    void *win_ptr;      // Window pointer

    // Initialize the MiniLibX graphics system
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL) {
        fprintf(stderr, "Error: Failed to initialize MiniLibX\n");
        return 1;
    }

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Circle Program");
    if (win_ptr == NULL) {
        fprintf(stderr, "Error: Failed to create a window\n");
        return 1;
    }

    // Calculate the radius and center coordinates of the circles
    int circle_radius = WIN_WIDTH / (NUM_CIRCLES * 2);
    int circle_center_x = WIN_WIDTH / 2;
    int circle_center_y = WIN_HEIGHT / 2;

    // Draw the circles on the window
    int i;
    for (i = 0; i < NUM_CIRCLES; i++) {
        // Calculate the angle for each circle
        double angle = 2 * M_PI * i / NUM_CIRCLES;

        // Calculate the position of the circle's center
        int x = circle_center_x + (int)(circle_radius * cos(angle));
        int y = circle_center_y + (int)(circle_radius * sin(angle));

        // Draw the circle on the window
        mlx_string_put(mlx_ptr, win_ptr, x - circle_radius, y, 0xFFFFFF, "O");
    }

    // Start the event loop
    mlx_loop(mlx_ptr);

    // Clean up resources and exit
    mlx_destroy_window(mlx_ptr, win_ptr);
    return 0;
}
