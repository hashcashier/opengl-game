/*
 * Planet.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "Planet.h"

//Planet::Planet() {
//	x = y = z = r = texture = list = 0;
//}

Planet::Planet(GLfloat X, GLfloat Y, GLfloat Z, GLdouble R, GLuint T) {
	x = X;
	y = Y;
	z = Z;
	r = R;
	texture = T;
	list = 0;
	light = false;
}

void Planet::draw() {
	if(!list) {
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		if(!light)
			glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, texture);

		GLUquadricObj *sphere= gluNewQuadric();
		gluQuadricDrawStyle(sphere, GLU_FILL);
		gluQuadricTexture(sphere, true);
		gluQuadricNormals(sphere, GLU_SMOOTH);
//		glRotated(90,1,0,0);
		glTranslated(x, y, z);
		gluSphere(sphere, r, 20000, 20000);
		gluDeleteQuadric(sphere);

		glEnable(GL_COLOR_MATERIAL);
		if(!light)
			glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glEndList();
	} else {
		glCallList(list);
	}
}
