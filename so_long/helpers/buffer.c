void buffer_init(program *vars)
{
    vars->buffer.width = vars->cam.width;
    vars->buffer.height = vars->cam.height;
    vars->buffer.img = mlx_new_image(vars->mlx, vars->buffer.width , vars->buffer.height);
	vars->buffer.data = (int *)mlx_get_data_addr(vars->buffer.img, &vars->buffer.bpp, &vars->buffer.size_line, &vars->buffer.endian);
}

void clear_buffer(program *vars)
{
    int pixels;
    int i;

    i = 0;
    pixels = vars->buffer.width * vars->buffer.height;
    while(i < pixels)
    {
        //vars->buffer.data[i] = 0;
        vars->buffer.data[i] = 0x25131A;
        
        i++;
    }
}
