/*
 * Universe.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "Universe.h"

void Universe::draw() {
	static GLuint texture = PNGTextureLoader::loadTexture("space.png");
	static GLuint list = 0;
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, texture);

	if(!list) {
		glPushMatrix();

		GLUquadricObj *sphere= gluNewQuadric();
		gluQuadricDrawStyle(sphere, GLU_FILL);
		gluQuadricTexture(sphere, true);
		gluQuadricNormals(sphere, GLU_SMOOTH);

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
//		glRotated(90,1,0,0);
		gluSphere(sphere, 15000, 2000, 2000);
		glEndList();
		gluDeleteQuadric(sphere);

		glPopMatrix();
	} else {
		glCallList(list);
	}

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
