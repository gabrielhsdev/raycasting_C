#ifndef RAYCASTER_GLOBALS_H
#define RAYCASTER_GLOBALS_H

#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define MAP_BLOCK_SIZE_PX 64 // Result of ( SCREEN_WIDTH / 2 ) / MAP_WIDTH
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 510
#define MAP_BLOCK_WIDTH SCREEN_WIDTH / MAP_WIDTH / 2
#define MAP_BLOCK_HEIGHT SCREEN_HEIGHT / MAP_HEIGHT
#define SCREEN_NAME "Raycaster"

typedef struct {
    float postion_x;
    float postion_y;

    float direction_x; // player direction x
    float direction_y; // player direction y

    float angle; // player angle

    float moveSpeed; // player move speed
    float rotSpeed; // player rotation speed

    float ray_size; // ray size
    float ray_angle; // ray angle
} Player;

// Create a player
Player player = {150, 400, 0, 0, -90, 5, 3, 100};


int worldMap[MAP_WIDTH][MAP_HEIGHT] =
        {
                1,1,1,1,1,1,1,1,
                1,0,1,0,0,0,0,1,
                1,0,1,0,0,0,0,1,
                1,0,1,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,1,1,1,1,1,1,1,
        };

#endif //RAYCASTER_GLOBALS_H