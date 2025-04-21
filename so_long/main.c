#include "mlx.h"
#include "mlx_int.h"
// Forbidden
#include <stdio.h>

#include "game.h"
#include "helpers/resize.c"
#include "helpers/subimage.c"

float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

int key_press(int key, program *vars) {


	printf("KEY:%d\n", key);

	if (key == LEFT_ARROW || key == A_KEY)
	{
	vars->player.x -= SPEED;
	}
	else if (key == UP_ARROW || key == W_KEY)
	{
	vars->player.y -= SPEED;
	}
	else if (key == RIGHT_ARROW || key == D_KEY)
	{
	vars->player.x += SPEED;
	}
	else if (key == DOWN_ARROW || key == S_KEY)
	{  // Down arrow key (move camera down)
	vars->player.y += SPEED;
	}
	else if (key == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		vars->window = NULL;
		return (0);
	}

    return 0;
}



int	close_window(int keycode, program *vars)
{
	//mlx_destroy_window(vars->mlx, vars->windows);
	printf("Hello World");
	return (0);
}

int key_hook(int keycode, program *vars)
{
	//printf("Goodbye!\n");
	//exit(0);
	return (0);
}


int mouse_hook(int keycode, program *vars)
{
	//printf("Hello!\n");
	//exit(0);
	return (0);
}


int mouse_move(int x, int y, void *param)
{
	printf("%d %d\n", x, y);
	//exit(0);
	return (0);
}

int render(program *vars)
{

	if (!vars->window)
		return (0);

	mlx_clear_window(vars->mlx, vars->window);


	// Offset na camera
	vars->cam.x = vars->player.x - 1920 / 2;
	vars->cam.y = vars->player.y - 1080 / 2;

	int player_screen_x = (int)(vars->player.x - vars->cam.x);
	int player_screen_y = (int)(vars->player.y - vars->cam.y);

	int mapa_x = (int)(0 - vars->cam.x);
	int mapa_y = (int)(0 - vars->cam.y);

	mlx_put_image_to_window(vars->mlx, vars->window, vars->images[0], mapa_x, mapa_y);
	//mlx_put_image_to_window(vars->mlx, vars->window, vars->images[0], mapa_x, mapa_y);

	//mlx_put_image_to_window(vars->mlx, vars->window, vars->images[2], 0, 0);

	mlx_string_put(vars->mlx, vars->window, player_screen_x, player_screen_y, 0xFF00FF, "Player");


	// Desenha UI
	mlx_string_put(vars->mlx, vars->window, 25, 25, 0xFF00FF, "Passos");
	mlx_string_put(vars->mlx, vars->window, 25, 50, 0xFF00FF, "Vida");

	// Desenha os inimigos
	for (int i = 0; i < 2; i++)
	{
        	int enemy_screen_x = (int)(vars->enemies[i].x - vars->cam.x);
        	int enemy_screen_y = (int)(vars->enemies[i].y - vars->cam.y);
        	mlx_string_put(vars->mlx, vars->window, enemy_screen_x, enemy_screen_y, 0xFF00FF, "Enemy");
    }

	//mlx_put_image_to_window(vars->mlx, vars->window, vars->image, 50, 50);

	return (0);
}


int main()
{
	program vars;
	int scale;

	vars.mlx = mlx_init();

	//resize_xpm_to_image(image, &vars);

	//int scale = 1080 / 270;
	scale = 2;
	int a, b;
	vars.window = mlx_new_window(vars.mlx, 1920, 1080, "karia I love you!");

	void *tilemap = mlx_xpm_file_to_image (vars.mlx, "assets/tilemap.xpm", &a, &b);
	void *map = mlx_xpm_file_to_image (vars.mlx, "assets/mapa.xpm", &a, &b);
	void *player = mlx_xpm_file_to_image (vars.mlx, "assets/Idle_0.xpm", &a, &b);
	
	//vars.images[0] = map;
	//vars.images[0] = map;
	vars.images[0] = resize(&vars, map, scale);
	//void *temp22 = sub_image(&vars, tilemap, 16, 16, 32, 32);
	//vars.images[2] = resize(&vars, temp22, scale);


	void *img;
	int	widht;
	int	height;


 	for (int i = 0; i < 2; i++)
 	{
		vars.enemies[i].x = i*300 + 50;
		vars.enemies[i].y = i*250 + 50;
		vars.enemies[i].width = 50;
		vars.enemies[i].height = 50;
    }

	vars.cam.x = 0;
	vars.cam.y = 0;
	vars.cam.width = 800;
	vars.cam.height = 600;



	mlx_loop_hook(vars.mlx, render, &vars);
    	//mlx_key_hook(vars.window, key_press, &vars);
	mlx_hook(vars.window, 2, 1L<<0, key_press, &vars);

	mlx_loop(vars.mlx);


	mlx_destroy_display(vars.mlx);
	free(vars.mlx);

}
