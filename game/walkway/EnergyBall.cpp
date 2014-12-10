/*
 * EnergyBall.cpp
 *
 *  Created on: Dec 10, 2014
 *      Author: rami
 */

#include "EnergyBall.h"

void EnergyBall::draw(GLfloat x, GLfloat y, GLfloat z, GLfloat s) {
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslated(x, y, z);
//	glRotated(-90, 1, 0, 0);
//	GLUquadricObj* esphere = gluNewQuadric();
//	gluQuadricTexture(esphere, true);
//	gluQuadricNormals(esphere, GLU_SMOOTH);
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_CULL_FACE);
//	gluSphere(esphere, 0.5, 100, 100);
	glutSolidSphere(0.5, 100, 100);
//	gluDeleteQuadric(esphere);
	glPopMatrix();
}
