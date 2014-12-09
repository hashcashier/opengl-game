/*
 * character.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "character.h"

GLuint Character::object = 0;
float Character::rotation = 0;

bool Character::hasObjectId() {
	return object != 0;
}

void Character::setObjectId(GLuint objectId) {
	object = objectId;
}

void Character::setRotation(float rot) {
	rotation = rot;
}

void Character::draw() {
	if(!hasObjectId())
		setObjectId(ObjectLoader::loadObject("al.obj"));

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

