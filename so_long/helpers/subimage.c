#include "../game.h"

void *sub_image(program *vars, void* source, int offset_x, int offset_y, int width, int height)
{

    int     *original_data;
    int     original_bits_per_pixel;
    int     original_endian;
    int     original_size_line;
		
    void    *sub_image;
    int     *sub_image_data;
    int     sub_image_bits_per_pixel;
    int     sub_image_endian;
    int     sub_image_size_line;


    //original =  mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
    //original_data = (int *)mlx_get_data_addr(original, &original_bits_per_pixel, &original_size_line, &original_endian);
    original_data = (int *)mlx_get_data_addr(source, &original_bits_per_pixel, &original_size_line, &original_endian);

    //mlx_xpm_to_image (vars->mlx, (char **)original_data, NULL, NULL);

    //original_data = (int *)mlx_get_data_addr(original, &bits_per_pixel, &size_line, &endian);

    sub_image = mlx_new_image(vars->mlx, width, height);
    sub_image_data = (int *)mlx_get_data_addr(sub_image, &sub_image_bits_per_pixel, &sub_image_size_line, &sub_image_endian);


    int     *resized_data;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            sub_image_data[((y * sub_image_size_line) / 4) + x] = original_data[((((y + offset_y)) * original_size_line) / 4) + ((x + offset_x))];
        }
    }
    
    return (sub_image);

}
