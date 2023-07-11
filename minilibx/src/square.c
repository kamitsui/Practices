/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:29:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/11 19:30:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 800  // Width of the window
#define WIN_HEIGHT 600 // Height of the window
#define SQUARE_SIZE 200 // Size of the square

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
    win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Square Program");
    if (win_ptr == NULL) {
        fprintf(stderr, "Error: Failed to create a window\n");
        return 1;
    }

    // Calculate the position of the square's top-left corner
    int square_x = (WIN_WIDTH - SQUARE_SIZE) / 2;
    int square_y = (WIN_HEIGHT - SQUARE_SIZE) / 2;

    // Draw the square on the window
    mlx_string_put(mlx_ptr, win_ptr, square_x, square_y, 0xFFFFFF, "Square");

    // Start the event loop
    mlx_loop(mlx_ptr);

    // Clean up resources and exit
    mlx_destroy_window(mlx_ptr, win_ptr);
    return 0;
}

//typedef struct	s_data {
//	void	*mlx;
//	void	*mlx_win;
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_data;
//
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}
//
//int		close_window(t_data *data)
//{
//	mlx_destroy_window(data->mlx, data->mlx_win);
//	exit(0);
//}
//
//int		main(void)
//{
//	t_data	img;
//
//	img.mlx = mlx_init();
//	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
//	img.img = mlx_new_image(img.mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000); // Put a red pixel at (100, 100)
//
//	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
//	mlx_hook(img.mlx_win, 17, 0, close_window, &img); // Handle window close event
//	mlx_loop(img.mlx);
//
//	return (0);
//}
//	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
