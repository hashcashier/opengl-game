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

using namespace std;

class EnergyBall {
public:
	static void draw(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
};

#endif /* ENERGYBALL_H_ */
