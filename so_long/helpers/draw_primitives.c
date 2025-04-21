#include "../game.h"

void draw_rectangle(int x, int y, int width, int height, int color)
{
    void *rect;
    
    rect = mlx_new_image(vars->mlx, width * scale, height * scale);

    resized_data = (int *)mlx_get_data_addr(resized_image, &bits_per_pixel_resized, &size_line_resized, &endian_resized);


    // https://github.com/iciamyplant/Cub3d-Linux
    for (int x = 0; x < width * scale; x++)
    {
        for (int y = 0; y < height * scale; y++)
        {
            //original_data[((y * size_line) / 4) + x] = 0xFF0000;
            //https://stackoverflow.com/questions/41861274/scaling-up-an-image-using-nearest-neighbor 
            // ISSO EH GENIAL! 
            resized_data[((y * size_line_resized) / 4) + x] = original_data[(((y / scale) * size_line) / 4) + (x / scale)];
        }
    }

}