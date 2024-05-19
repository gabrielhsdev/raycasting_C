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
        player.angle = FixAng(player.angle - player.rotSpeed);
        player.direction_x = cos(degToRad(player.angle));
        player.direction_y = sin(degToRad(player.angle));
    }
    if (key=='d')
    {
        player.angle = FixAng(player.angle + player.rotSpeed);
        player.direction_x = cos(degToRad(player.angle));
        player.direction_y = sin(degToRad(player.angle));
    }
    // Print player angle
    printf("Angle: %f\n",player.angle);
    glutPostRedisplay();
}

void DrawRays3D()
{
    float ray_vertical_x, ray_vertical_y ,ray_y, ray_x, ray_angle, ray_inc_x, ray_inc_y, distance_v, distance_h;
    int r, map_x , map_y, map_pos, depth_of_field;

    player.ray_angle = player.angle;
    So, the code you are seeing, help me divide it into more files.
    for(r = 0; r < 1; r++)
    {
        // Check Horizontal Lines
        float aTan = -1/tan(degToRad(player.ray_angle));
        depth_of_field = 0;

        if (player.ray_angle > 180 || player.ray_angle < 0) // Looking up
        {
            // ry=(((int)py>>6)<<6) -0.0001; rx=(py-ry)*Tan+px; yo=-64; xo=-yo*Tan;
            ray_y = (((int)player.postion_y / MAP_BLOCK_SIZE_PX) * MAP_BLOCK_SIZE_PX) - 0.0001;
            ray_x = (player.postion_y - ray_y) * aTan + player.postion_x;
            ray_inc_y = -MAP_BLOCK_SIZE_PX;
            ray_inc_x = -ray_inc_y * aTan;
        } else if (player.ray_angle < 180 && player.ray_angle > 0) // Looking down
        {

        } else // Looking straight
        {
            printf("Looking straight\n");
        }

        // Draw red dot on the intersection point
        glColor3f(1,0,0);
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2i(ray_x,ray_y);
        glEnd();
    }
}

void DrawRay2D(int x1,int y1,int x2,int y2)
{
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
}

void DrawPlayer2D()
{
    glColor3f(1,0,0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player.postion_x,player.postion_y);
    glEnd();
    DrawRay2D(
            player.postion_x,
            player.postion_y,
            player.postion_x+player.direction_x*player.ray_size,
            player.postion_y+player.direction_y*player.ray_size
    );
}

void DrawMap2D () {
    for(int y = 0; y < MAP_WIDTH; y++)
    {
        for(int x = 0; x < MAP_HEIGHT; x++)
        {
            if(worldMap[x][y] == 1) {
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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawMap2D();
    DrawPlayer2D();
    DrawRays3D();
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