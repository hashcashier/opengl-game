/*
 * character.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "character.h"

Character::Character(GLuint objectId) {
	object = objectId;
	rotation = 0;
}

void Character::setRotation(float rot) {
	rotation = rot;
}

void Character::draw() {
	glPushMatrix();
	glTranslated(-1,-5.00,20);
	glColor3d(0.3,0.1,0.9);
	//glScalef(0.1,0.1,0.1);
	glScaled(0.2,0.2,0.2);
	glRotated(rotation,0,1,0);
	cerr << "Character: " << object << endl;
	glCallList(object);
	glPopMatrix();
}

