#include "render.h"
#include <math.h>
#include <GL/glut.h>

#include "../../globals.h"
#include "../../utils/utils.h"
#include "../../player/player.h"

void DrawWall3D( float distance_v, float distance_h, int r )
{
    // DRAW 3D WALL
    float final_distance = distance_v < distance_h ? distance_v : distance_h;
    final_distance = final_distance * cos(degToRad(player.ray_angle - player.angle));
    float wall_height = (MAP_BLOCK_SIZE_PX / final_distance) * (SCREEN_WIDTH / 2) / tan(degToRad(30));
    float wall_start = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    float wall_end = (SCREEN_HEIGHT / 2) + (wall_height / 2);

    // Draw 3D Wall
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2i(r * 8 + SCREEN_WIDTH/2, wall_start);
    glVertex2i(r * 8 + SCREEN_WIDTH/2, wall_end);
    glVertex2i(r * 8 + SCREEN_WIDTH/2 + 8, wall_end);
    glVertex2i(r * 8 + SCREEN_WIDTH/2 + 8, wall_start);
    glEnd();
}