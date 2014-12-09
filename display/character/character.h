/*
 * character.h
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../../platformIndependentHeader.h"
#include "../../opengl/ObjectLoader.h"
using namespace std;

class Character {
	GLuint object;
	float rotation;
public:
	Character(GLuint objectId);
	void setRotation(float rot);
	void draw();
};

#endif /* CHARACTER_H_ */
