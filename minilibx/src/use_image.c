#include <mlx.h>
#include <stdio.h>

int main() {
    void *mlx_ptr;      // MiniLibX instance
    void *win_ptr;      // Window instance
    void *img_ptr;      // Image instance
//    int width, height;  // Image width and height
    int bits_per_pixel; // Bits per pixel in the image
    int size_line;      // Size of a single line in bytes
    int endian;         // Endianness of the image data

    // Initialize the MiniLibX graphics system
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL) {
        fprintf(stderr, "Error: Failed to initialize MiniLibX\n");
        return 1;
    }

    // Create a new window and image
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Image Example");
    img_ptr = mlx_new_image(mlx_ptr, 400, 300);

    // Get information about the image data
    char *img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
    if (img_data == NULL) {
        fprintf(stderr, "Error: Failed to get image data\n");
        return 1;
    }

    // Print the image information
    printf("Image data address: %p\n", img_data);
    printf("Bits per pixel: %d\n", bits_per_pixel);
    printf("Size of a single line: %d bytes\n", size_line);

    //printf("Endianness: %s\n", (endian == MLX_BIG_ENDIAN) ? "Big Endian" : "Little Endian");

    // ... (Draw on the image or manipulate the image data if needed)

    // Start the event loop
    mlx_loop(mlx_ptr);

    // Clean up resources and exit
    mlx_destroy_window(mlx_ptr, win_ptr);
    return 0;
}

