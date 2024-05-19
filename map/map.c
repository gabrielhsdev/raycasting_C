#include <GL/glut.h>
#include "map.h"

int MAP_WORLD[MAP_WIDTH][MAP_HEIGHT] =
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

void DrawMap2D () {
    for(int y = 0; y < MAP_WIDTH; y++)
    {
        for(int x = 0; x < MAP_HEIGHT; x++)
        {
            if(MAP_WORLD[x][y] == 1) {
                glColor3f(1, 1, 1);
            } else {
                glColor3f(0, 0, 0);
            }
            glBegin(GL_QUADS);
            glVertex2i(y*MAP_BLOCK_WIDTH + 1, x*MAP_BLOCK_HEIGHT + 1);
            glVertex2i(y*MAP_BLOCK_WIDTH + 1, x*MAP_BLOCK_HEIGHT+MAP_BLOCK_HEIGHT - 1);
            glVertex2i(y*MAP_BLOCK_WIDTH+MAP_BLOCK_WIDTH - 1, x*MAP_BLOCK_HEIGHT+MAP_BLOCK_HEIGHT - 1);
            glVertex2i(y*MAP_BLOCK_WIDTH+MAP_BLOCK_WIDTH -1, x*MAP_BLOCK_HEIGHT + 1);
            glEnd();
        }
    }
}