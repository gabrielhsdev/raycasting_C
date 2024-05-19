#ifndef RAYCASTER_PLAYER_H
#define RAYCASTER_PLAYER_H

#include <GL/glut.h>
#include <math.h>
#include "../utils/utils.h"
#include "../rays/rays.h"

// Structs
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

extern Player player;

// Functions
void Buttons(unsigned char key, int x, int y);

void DrawPlayer2D();

#endif //RAYCASTER_PLAYER_H
