#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Includes
#include "utils/utils.h"
#include "globals.h"
#include "player/player.h"
#include "map/map.h"
#include "rays/rays.h"

void init()
{
    glClearColor(0.3,0.3,0.3,0);
    gluOrtho2D(0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    player.direction_x = cos(degToRad(player.angle));
    player.direction_y = sin(degToRad(player.angle));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawMap2D();
    DrawPlayer2D();
    DrawRays2D();
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    glutCreateWindow(SCREEN_NAME);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(Buttons);
    glutMainLoop();
}