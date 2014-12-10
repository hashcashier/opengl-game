/*
 * walkway.h
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#ifndef WALKWAY_H_
#define WALKWAY_H_

#include "../../platformIndependentHeader.h"
#include "../../display/shapes/Cube.h"
#include "../../opengl/TextureLoader.h"
#include "../../display/shapes/Position.h"
#include "EnergyBall.h"

using namespace std;

extern void cube_textured(int x, int y, int z);
extern void cube(int x, int y, int z);
extern GLuint LoadTexture(const char * filename, int width, int height, int wrap);

void drawWalkway();
void drawEndWall();
bool hasObstacle(int x, int z);

class Walkway {
	static GLuint walkwayList;
	static vector<Position> energyBalls;
public:
	static const int LEFT_LIMIT, RIGHT_LIMIT;
	static const int LOW_LIMIT, HIGH_LIMIT;
	static bool nearEnergy(GLfloat x, GLfloat y, GLfloat z);
	static int nearestEnergy(GLfloat x, GLfloat y, GLfloat z);
	static void draw();
	static void reset();
	static void removeBall(int i);
};


#endif /* WALKWAY_H_ */
