#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "globals.h"

float degToRad(int a) { return a*M_PI/180.0;}
int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

void init()
{
    glClearColor(0.3,0.3,0.3,0);
    gluOrtho2D(0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    player.direction_x = cos(degToRad(player.angle));
    player.direction_y = sin(degToRad(player.angle));
}

void Buttons(unsigned char key,int x,int y)
{
    printf("Key: %c\n",key);
    if(key=='w')
    {
        player.postion_x += player.direction_x*player.moveSpeed;
        player.postion_y += player.direction_y*player.moveSpeed;
    }
    if(key=='s')
    {
        player.postion_x -= player.direction_x*player.moveSpeed;
        player.postion_y -= player.direction_y*player.moveSpeed;
    }
    if (key=='a')
    {
        player.angle -= player.rotSpeed;
        player.direction_x = cos(degToRad(player.angle));
        player.direction_y = sin(degToRad(player.angle));
    }
    if (key=='d')
    {
        player.angle += player.rotSpeed;
        player.direction_x = cos(degToRad(player.angle));
        player.direction_y = sin(degToRad(player.angle));
    }

    glutPostRedisplay();
}

void DrawPlayer2D()
{
    glColor3f(1,0,0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player.postion_x,player.postion_y);
    glEnd();
}

void DrawRay2D(int x1,int y1,int x2,int y2)
{
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
}

void DrawMap2D () {
    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            if(worldMap[x][y] == 1)
            {
                glColor3f(1,1,1);
                glBegin(GL_QUADS);
                glVertex2i(x*MAP_BLOCK_WIDTH, y*MAP_BLOCK_HEIGHT);
                glVertex2i(x*MAP_BLOCK_WIDTH, y*MAP_BLOCK_HEIGHT+MAP_BLOCK_HEIGHT);
                glVertex2i(x*MAP_BLOCK_WIDTH+MAP_BLOCK_WIDTH, y*MAP_BLOCK_HEIGHT+MAP_BLOCK_HEIGHT);
                glVertex2i(x*MAP_BLOCK_WIDTH+MAP_BLOCK_WIDTH, y*MAP_BLOCK_HEIGHT);
                glEnd();
            }
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawMap2D();
    DrawPlayer2D();
    DrawRay2D(
            player.postion_x,
            player.postion_y,
            player.postion_x+player.direction_x*player.ray_size,
            player.postion_y+player.direction_y*player.ray_size
            );
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