#include "raycasting.h"

/* Global map array */
const char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
	"################",
	"#..............#",
	"#..............#",
	"#....##........#",
	"#....##........#",
	"#..............#",
	"#..............#",
	"#......##......#",
	"#......##......#",
	"#..............#",
	"#..............#",
	"#....#...#.....#",
	"#....#...#.....#",
	"#..............#",
	"#..............#",
	"################"
};

/**
 * cast_rays - Performs raycasting and fills the screen buffer
 * @player: Pointer to the player struct
 * @screen: 2D array representing the screen buffer
 */
void cast_rays(Player *player, char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1])
{
	int x, y, wall_height, draw_start, draw_end;
	double ray_angle, ray_x, ray_y, step_size, dist;

	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		ray_angle = (player->angle - FOV / 2.0) + ((double)x / SCREEN_WIDTH) * FOV;
		ray_x = player->x;
		ray_y = player->y;
		step_size = 0.1;
		dist = 0;

		while (1)
		{
			dist += step_size;
			ray_x = player->x + cos(ray_angle) * dist;
			ray_y = player->y + sin(ray_angle) * dist;

			if (map[(int)ray_y][(int)ray_x] == '#')
				break;
		}

		wall_height = (int)((SCREEN_HEIGHT / dist) * 0.5);
		draw_start = -wall_height / 2 + SCREEN_HEIGHT / 2;
		draw_end = wall_height / 2 + SCREEN_HEIGHT / 2;

		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;

		for (y = 0; y < SCREEN_HEIGHT; y++)
		{
			if (y < draw_start)
				screen[y][x] = ' ';
			else if (y >= draw_start && y <= draw_end)
				screen[y][x] = '#';
			else
				screen[y][x] = '.';
		}
	}
}

/**
 * render_screen - Clears the console and prints the screen buffer
 * @screen: 2D array representing the screen buffer
 */
void render_screen(char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1])
{
	int y;

	printf("\033[H\033[J");  /* Clear the console */
	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		printf("%s\n", screen[y]);
	}
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	Player player = {8.0, 8.0, 0};
	char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1];
	int i;
	char input;

	for (i = 0; i < SCREEN_HEIGHT; i++)
	{
		memset(screen[i], ' ', SCREEN_WIDTH);
		screen[i][SCREEN_WIDTH] = '\0';
	}

	while (1)
	{
		cast_rays(&player, screen);
		render_screen(screen);

		printf("Use 'a' to rotate left, 'd' to rotate right, 'q' to quit: ");
		input = getchar();
		while (getchar() != '\n')
			; /* Clear input buffer */

		if (input == 'a')
			player.angle -= 0.1;
		else if (input == 'd')
			player.angle += 0.1;
		else if (input == 'q')
			break;
	}

	return (0);
}

