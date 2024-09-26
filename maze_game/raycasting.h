#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAP_WIDTH 16
#define MAP_HEIGHT 16
#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20
#define FOV (M_PI / 3)

/**
 * struct Player - Represents the player's position and orientation
 * @x: x-coordinate of the player
 * @y: y-coordinate of the player
 * @angle: viewing angle of the player
 */
typedef struct Player
{
	double x;
	double y;
	double angle;
} Player;

void cast_rays(Player *player, char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1]);
void render_screen(char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1]);

#endif /* RAYCASTING_H */

