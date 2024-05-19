#include "rays.h"

#include <stdio.h>
#include <GL/glut.h>

void DrawRays2D()
{
    float ray_vertical_x, ray_vertical_y, ray_y, ray_x, ray_angle, ray_inc_x, ray_inc_y, distance_v, distance_h;
    int r, map_x, map_y, map_pos, depth_of_field;

    player.ray_angle = player.angle;
    for (r = 0; r < 1; r++) {
        // Check Horizontal Lines
        float aTan = -1 / tan(degToRad(player.ray_angle));
        depth_of_field = 0;

        if (player.ray_angle > 180 || player.ray_angle < 0) // Looking up
        {
            ray_y = (((int) player.postion_y / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) - 0.0001;
            ray_x = (player.postion_y - ray_y) * aTan + player.postion_x;
            ray_inc_y = -MAP_BLOCK_SIZE_PX;
            ray_inc_x = -ray_inc_y * aTan;
            printf("Ray x %f y %f\n", ray_x, ray_y);
        } else if (player.ray_angle < 180 && player.ray_angle > 0) // Looking down
        {
            ray_y = (((int) player.postion_y / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) + 64;
            ray_x = (player.postion_y - ray_y) * aTan + player.postion_x;
            ray_inc_y =  MAP_BLOCK_SIZE_PX;
            ray_inc_x = -ray_inc_y * aTan;
            printf("Ray x %f y %f\n", ray_x, ray_y);
        } else // Looking straight
        {
            printf("Looking straight\n");
        }


        while (depth_of_field < 10) {
            map_x = (int) (ray_x / MAP_BLOCK_SIZE_PX);
            map_y = (int) (ray_y / MAP_BLOCK_SIZE_PX);
            map_pos = map_y * MAP_WIDTH + map_x;

            if (map_x >= 0 && map_x < MAP_WIDTH && map_y >= 0 && map_y < MAP_HEIGHT && MAP_WORLD[map_y][map_x] == 1) {
                distance_h = distance(player.postion_x, player.postion_y, ray_x, ray_y);
                printf("Distance H %f\n", distance_h);
                break;
            } else {
                ray_x += ray_inc_x;
                ray_y += ray_inc_y;
                depth_of_field++;
            }
        }

        // Draw red dot on the intersection point
        glColor3f(1, 0, 0);
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2i(ray_x, ray_y);
        glEnd();
    }
}

void DrawRay2D(int x1, int y1, int x2, int y2) {
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}