/*
 * Coin.h
 *
 *  Created on: Dec 10, 2014
 *      Author: rami
 */

#ifndef COIN_H_
#define COIN_H_

#include "../../platformIndependentHeader.h"
#include "../../display/shapes/Position.h"
#include "../../display/universe/Planet.h"
using namespace std;

class Coin {
	GLfloat x, y, z, s;
	Planet planet;
public:
//	static void draw(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
	Coin(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
	void draw();
	static GLuint texture;
};

#endif /* COIN_H_ */
