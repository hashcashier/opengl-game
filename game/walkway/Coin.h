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
using namespace std;

class Coin {
public:
	static void draw(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
};

#endif /* COIN_H_ */
