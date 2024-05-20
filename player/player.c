#include "player.h"

#include <stdio.h>
// Define a player
Player player = {150, 400, 0, 0, -90, 5, 3, 100};

void Buttons(unsigned char key,int x,int y)
{
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
    //printf("Player x %d y %d\n",player.postion_x,player.postion_y);
    glutPostRedisplay();
}

void DrawPlayer2D()
{
    glColor3f(1,0,0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player.postion_x,player.postion_y);
    glEnd();
    /*
    DrawRay2D(
            player.postion_x,
            player.postion_y,
            player.postion_x+player.direction_x*player.ray_size,
            player.postion_y+player.direction_y*player.ray_size
    );
     */
}