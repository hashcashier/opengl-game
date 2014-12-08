/*
 * walkway.h
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "../../platformIndependentHeader.h"
using namespace std;

#ifndef WALKWAY_H_
#define WALKWAY_H_

extern void cube_textured(int x, int y, int z);
extern void cube(int x, int y, int z);
extern GLuint LoadTexture( const char * filename, int width, int height, int wrap );

void drawWalkway();
void drawEndWall();
void drawObstacles(int x, int y, int z);
bool hasObstacle(int x, int z);


#endif /* WALKWAY_H_ */
