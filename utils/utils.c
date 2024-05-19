#include "utils.h"

float degToRad(int a) { return a*M_PI/180.0;}
int FixAng(int a)
{
    if(a>359)
    {
        a-=360;
    }
    if(a<0)
    {
        a+=360;
    }
    return a;
}

float distance(float x1, float y1, float x2, float y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
