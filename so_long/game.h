#include "mlx.h"
#include "mlx_int.h"

#ifndef GAME_H
#define GAME_H

#define SPEED 5

enum Key
{
	ESC = 65307,
	UP_ARROW = 65362,
	W_KEY = 119,
	S_KEY = 115,
	A_KEY = 97,
	D_KEY = 100,
	DOWN_ARROW = 65364,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363,
	KEY_R = 114
};

typedef struct
{
	void *img;
	int height;
	int widht;
	int	x;
	int y;
} Image;


typedef struct
{
	int x;
	int y;
	int width;
	int height;
} Camera;

typedef struct
{
	float x;
	float y;
	int dx;
	int dy;
} Player;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Enemy;

typedef struct
{
	void *mlx;
	void *window;
	void *scale_frame;
	int mouse_x;
	int mouse_y;
	void* image;
	void* image_2;
	void* mapa;
	void* images[256];
	Camera cam;
	Player player;
	Enemy enemies[2];
}	program;



#endif
