#include "../game.h"

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void* resize(program *vars, void *image, int scale)
{
    int     width;
    int     height;
    int    *original_data;
    
    int     bits_per_pixel;
    int     bits_per_pixel_resized; 

    int     size_line;
    int     size_line_resized;

    int     endian_resized;


    int     endian;
    char    *pixels;
    void    *resized_image;
    int     *resized_data;

    //original =  mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
    original_data = (int *)mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);

    resized_image = mlx_new_image(vars->mlx, width * scale, height * scale);
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

    return (resized_image);

}
