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
	static GLfloat x, y, z;
	static const GLfloat iX, iY, iZ;
public:
	static bool hasObjectId();
	static void setObjectId(GLuint objectId);
	static void setRotation(float rot);
	static void draw();

	static GLfloat getX();
	static void setX(GLfloat X);
	static GLfloat getY();
	static void setY(GLfloat Y);
	static GLfloat getZ();
	static void setZ(GLfloat Z);

	static void resetPosition();
	static void moveForward(GLfloat value);
	static void moveLeft(GLfloat value);
	static void moveRight(GLfloat value);
};

#endif /* CHARACTER_H_ */
