/*
 * EnergyBall.h
 *
 *  Created on: Dec 10, 2014
 *      Author: rami
 */

#ifndef ENERGYBALL_H_
#define ENERGYBALL_H_

#include "../../platformIndependentHeader.h"
#include "../../display/shapes/Position.h"
#include "../../opengl/textures/PNGTextureLoader.h"
#include "../../display/universe/Planet.h"

using namespace std;

class EnergyBall {
	GLfloat x, y, z, s;
	Planet planet;
public:
	EnergyBall(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
	void draw();
	static GLuint texture;
};

#endif /* ENERGYBALL_H_ */
