/*
 * Planet.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#ifndef PLANET_H_
#define PLANET_H_

#include "../../platformIndependentHeader.h"
using namespace std;

class Planet {
	GLfloat x, y, z;
	GLdouble r;
	GLuint texture, list;
public:
//	Planet();
	bool light;
	Planet(GLfloat X, GLfloat Y, GLfloat Z, GLdouble R, GLuint T);
	void draw();
};

#endif /* PLANET_H_ */
