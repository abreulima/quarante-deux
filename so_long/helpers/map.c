#include "../game.h"

#include <stdlib.h>
#include <stdio.h>

const int tilemap_tile_size = 16;

#define ROWS 16
#define COLS 16
/*
char map[ROWS][COLS] = 
{ //  1    2    3   4    5     6   7     8   9    10   11   12   13   14   15   16
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 1
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1'}, // 2
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 3
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 4
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 5
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 6
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 7
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 8
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 9
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 10 
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 11
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 12
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 13
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 14
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 15
};
*/


char map[ROWS][COLS] = 
{ //  1    2    3   4    5     6   7     8   9    10   11   12   13   14   15   16
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 1
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 15
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 3
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 4
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 5
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 6
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 7
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 8
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 9
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 10 
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 11
    {'1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, // 12
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 13
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 15
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 15
};

/* cl
It uses bitmasking
// - 1 -16
// 2 - 4
// - 8 -
*/

// 001 002 004
// 008  -  016
// 032 064 128

int get_tile_type(int row, int col)
{
	int total;

    total = 0;
    if (col > 0)              total += 1;  // Left
    if (row > 0)              total += 2;  // Up
    if (row < ROWS - 1)       total += 4;  // Down
    if (col < COLS - 1)       total += 8;  // Right

    /*
    if (row > 0 && col > 0)              total += 16;
    if (row > 0 && col < COLS - 1)       total += 32;
    if (row < ROWS - 1 && col > 0)       total += 64;
    if (row < ROWS -1 && col < COLS - 1) total += 128;
*/
	return (total);
}


void copy_tile_to_buffer(program *vars, void *tile_img, int dst_x, int dst_y)
{
    int x, y;
    int tile_width = 32;  // Assuming your tiles are 32x32 after scaling
    int tile_height = 32;
    int *tile_data;
    int *buffer_data;
    int tile_bpp, tile_size_line, tile_endian;
    
    // Get the tile image data
    tile_data = (int *)mlx_get_data_addr(tile_img, &tile_bpp, &tile_size_line, &tile_endian);
    
    // Get the buffer data
    buffer_data = (int *)vars->buffer.data;
    
    // Copy pixel by pixel
    for (y = 0; y < tile_height; y++)
    {
        for (x = 0; x < tile_width; x++)
        {
            // Calculate buffer position
            int buf_x = dst_x + x;
            int buf_y = dst_y + y;
            
            // Check if the pixel is within buffer bounds
            if (buf_x >= 0 && buf_x < vars->buffer.width && 
                buf_y >= 0 && buf_y < vars->buffer.height)
            {
                // Get the pixel from tile
                int tile_pixel = tile_data[y * (tile_size_line / 4) + x];
                
                // Skip transparent pixels (assuming 0 is transparent)
                if (tile_pixel != 0)
                {
                    // Set pixel in buffer
                    buffer_data[buf_y * (vars->buffer.size_line / 4) + buf_x] = tile_pixel;
                }
            }
        }
    }
}


void draw_tile(program *vars, int x, int y, char type, Camera cam)
{
    int tile_type;
    char buffer[100];

    tile_type = get_tile_type(x, y);
    sprintf(buffer,"%d",tile_type);

    mlx_put_image_to_window(vars->mlx, vars->window, vars->tiles[tile_type], 32 * x, 32 * y);
    //mlx_string_put(vars->mlx, vars->window, 32*x + 8 , 32 * y + 16 + 8, 0xFF0000, buffer);
    //if (type == '0')
        //mlx_put_image_to_window(vars->mlx, vars->window, vars->tiles[TILE_FLOOR], 32 * x, 32 * y);
}

void draw_map(program *vars)
{
    int row;
    int col;

    row = 0;
    while (row < ROWS)
    {
        col = 0;
        while (col < COLS)
        {
            //printf("%d %d\n", row, col);
            draw_tile(vars, col, row, map[row][col], vars->cam);
            col++;
        }
        row++;
    }

}
