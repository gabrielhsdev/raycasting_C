#ifndef RAYCASTER_MAP_H
#define RAYCASTER_MAP_H

#include "../globals.h"

#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define MAP_BLOCK_WIDTH SCREEN_WIDTH / MAP_WIDTH / 2
#define MAP_BLOCK_HEIGHT SCREEN_HEIGHT / MAP_HEIGHT
#define MAP_BLOCK_SIZE_PX 64 // Result of ( SCREEN_WIDTH / 2 ) / MAP_WIDTH

// Variables
extern int MAP_WORLD[MAP_WIDTH][MAP_HEIGHT];

// Functions
void DrawMap2D();

#endif //RAYCASTER_MAP_H