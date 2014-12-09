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
	static GLuint object;
	static float rotation;
public:
	static bool hasObjectId();
	static void setObjectId(GLuint objectId);
	static void setRotation(float rot);
	static void draw();
};

#endif /* CHARACTER_H_ */
