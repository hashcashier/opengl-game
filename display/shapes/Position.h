/*
 * Position.h
 *
 *  Created on: Dec 10, 2014
 *      Author: rami
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "../../platformIndependentHeader.h"
using namespace std;

class Position {
public:
	GLfloat x, y, z;
	Position(GLfloat x, GLfloat y, GLfloat z);
};

#endif /* POSITION_H_ */
