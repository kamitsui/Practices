/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_image_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:28:17 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/17 16:18:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void mlx_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        // Set the pixel color at the current position (x0, y0)
        mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        int err2 = 2 * err;

        if (err2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (err2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
int	main(void)
{
	void	*mlx;		// MiniLibX graphics system pointer
	void	*mlx_win;	// Window pointer
	t_data	data;		// Image pointer

	// Initialize the MiniLibX graphics system
	mlx = mlx_init();

	// Create a new window
	mlx_win = mlx_new_window(mlx, 1000, 800, "Hello world!");

	// Create a new image
	data.img = mlx_new_image(mlx, 800, 600);

	// Get the image data address and information
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line,
								&data.endian);

	// Output the retrieved information
	printf("Bits per pixel: %d\n", data.bits_per_pixel);
	printf("Size of each line: %d bytes\n", data.size_line);
	printf("Endianness: %d\n", data.endian);

	// Set pixel
	//my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	//draw_line_to_data(data, 0, 0, 100, 200, 0x00FFFFFF);

	// Put pixel
	mlx_put_image_to_window(mlx, mlx_win, data.img, 100, 100);


	mlx_loop(mlx);

	// Clean up resource and exit
	// mlx_destroy_window(mlx, win_ptr);
	// mlx_destroy_image(mlx_ptr, img_ptr);
	return 0;
}
