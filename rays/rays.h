#ifndef RAYCASTER_RAYS_H
#define RAYCASTER_RAYS_H

#include <GL/glut.h>

#include "../player/player.h"
#include "../utils/utils.h"
#include "../map/map.h"

// 2D Functions
void DrawPlayer2D();
void DrawRay2D(int x1, int y1, int x2, int y2, int r, int g, int b, float lineWidth);
void DrawRays2D();

#endif //RAYCASTER_RAYS_H
