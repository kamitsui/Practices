/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:53:24 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/11 14:11:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;	// MiniLibX graphics system pointe
	void	*win_ptr;	// Window pointer

	// Initialize the MiniLibx graphics system
	mlx_ptr = mlx_init();

	// Create a new window
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Window");

	// Perform further graphics operations on the created window

	// Close the window and release resources when done
//	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);

	return 0;
}
