#include "rays.h"

#include <stdio.h>
#include <GL/glut.h>

void DrawRays2D()
{
    float ray_vertical_x, ray_vertical_y, ray_horizontal_y, ray_horizontal_x, ray_inc_x, ray_inc_y, distance_v, distance_h, ray_x, ray_y;
    int r, map_x, map_y, depth_of_field;
    player.ray_angle = player.angle;

    for (r = 0; r < 1; r++) {
        // Check Horizontal Lines
        depth_of_field = 0;
        distance_h = 100000;
        ray_horizontal_y = player.postion_y;
        ray_horizontal_x = player.postion_x;
        float aTan = -1 / tan(degToRad(player.ray_angle));

        // Looking foward
        if (player.ray_angle > 180 || player.ray_angle < 0) // Looking up
        {
            ray_y = (((int) player.postion_y / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) - 0.0001;
            ray_x = (player.postion_y - ray_y) * aTan + player.postion_x;
            ray_inc_y = -MAP_BLOCK_SIZE_PX;
            ray_inc_x = -ray_inc_y * aTan;
        } else if (player.ray_angle < 180 && player.ray_angle > 0) // Looking down
        {
            ray_y = (((int) player.postion_y / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) + MAP_BLOCK_SIZE_PX;
            ray_x = (player.postion_y - ray_y) * aTan + player.postion_x;
            ray_inc_y = MAP_BLOCK_SIZE_PX;
            ray_inc_x = -ray_inc_y * aTan;
        } else {
            ray_x = player.postion_x;
            ray_y = player.postion_y;
            depth_of_field = DEPTH_OF_FIELD;
        }

        while (depth_of_field < DEPTH_OF_FIELD) {
            map_x = (int) (ray_x / MAP_BLOCK_SIZE_PX);
            map_y = (int) (ray_y / MAP_BLOCK_SIZE_PX);
            ray_horizontal_x = ray_x;
            ray_horizontal_y = ray_y;
            distance_h = distance(player.postion_x, player.postion_y, ray_horizontal_x, ray_horizontal_y);

            if (map_x >= 0 && map_x < MAP_WIDTH && map_y >= 0 && map_y < MAP_HEIGHT && MAP_WORLD[map_y][map_x] == 1) {
                distance_h = distance(player.postion_x, player.postion_y, ray_horizontal_x, ray_horizontal_y);
                depth_of_field = DEPTH_OF_FIELD;
                break;
            } else {
                ray_x += ray_inc_x;
                ray_y += ray_inc_y;
                depth_of_field += 1;
            }
        }

        // Check Vertical Lines
        depth_of_field = 0;
        distance_v = 100000;
        ray_vertical_y = player.postion_y;
        ray_vertical_x = player.postion_x;
        float nTan = -tan(degToRad(player.ray_angle));

        // Looking right
        if (player.ray_angle < 90 || player.ray_angle > 270) {
            ray_x = (((int) player.postion_x / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) + MAP_BLOCK_SIZE_PX;
            ray_y = (player.postion_x - ray_x) * nTan + player.postion_y;
            ray_inc_x = MAP_BLOCK_SIZE_PX;
            ray_inc_y = -ray_inc_x * nTan;
        } else if (player.ray_angle > 90 && player.ray_angle < 270) // Looking left
        {
            ray_x = (((int) player.postion_x / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) - 0.0001;
            ray_y = (player.postion_x - ray_x) * nTan + player.postion_y;
            ray_inc_x = -MAP_BLOCK_SIZE_PX;
            ray_inc_y = -ray_inc_x * nTan;
        } else {
            ray_x = player.postion_x;
            ray_y = player.postion_y;
            depth_of_field = DEPTH_OF_FIELD;
        }

        while (depth_of_field < DEPTH_OF_FIELD) {
            map_x = (int) (ray_x / MAP_BLOCK_SIZE_PX);
            map_y = (int) (ray_y / MAP_BLOCK_SIZE_PX);
            ray_vertical_x = ray_x;
            ray_vertical_y = ray_y;
            distance_v = distance(player.postion_x, player.postion_y, ray_vertical_x, ray_vertical_y);

            if (map_x >= 0 && map_x < MAP_WIDTH && map_y >= 0 && map_y < MAP_HEIGHT && MAP_WORLD[map_y][map_x] == 1) {
                distance_v = distance(player.postion_x, player.postion_y, ray_vertical_x, ray_vertical_y);
                depth_of_field = DEPTH_OF_FIELD;
                break;
            } else {
                ray_x += ray_inc_x;
                ray_y += ray_inc_y;
                depth_of_field += 1;
            }
        }

        // Draw the smallest distance
        if (distance_v < distance_h) {
            DrawRay2D(player.postion_x, player.postion_y, ray_vertical_x, ray_vertical_y, 0, 1, 0, 1);
        } else {
            DrawRay2D(player.postion_x, player.postion_y, ray_horizontal_x, ray_horizontal_y, 0, 1, 0, 1);
        }
    }
}

void DrawRay2D(int x1, int y1, int x2, int y2, int r, int g, int b, float lineWidth)
{
    glColor3f(r, g, b);
    glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}