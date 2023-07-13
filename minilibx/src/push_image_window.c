/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_image_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:28:17 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/11 22:10:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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

int	main(void)
{
	void	*mlx;		// MiniLibX graphics system pointer
	void	*mlx_win;	// Window pointer
	t_data	data;		// Image pointer

	// Initialize the MiniLibX graphics system
	mlx = mlx_init();

	// Create a new window
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	// Create a new image
	data.img = mlx_new_image(mlx, 1920, 1080);

	// Get the image data address and information
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line,
								&data.endian);

	// Output the retrieved information
	printf("Bits per pixel: %d\n", data.bits_per_pixel);
	printf("Size of each line: %d bytes\n", data.size_line);
	printf("Endianness: %d\n", data.endian);

	// Set pixel
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);

	// Put pixel
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);


	mlx_loop(mlx);

	// Clean up resource and exit
	// mlx_destroy_window(mlx, win_ptr);
	// mlx_destroy_image(mlx_ptr, img_ptr);
	return 0;
}
