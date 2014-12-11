/*
 * EnergyBall.cpp
 *
 *  Created on: Dec 10, 2014
 *      Author: rami
 */

#include "EnergyBall.h"

GLuint EnergyBall::texture;

EnergyBall::EnergyBall(GLfloat x, GLfloat y, GLfloat z, GLfloat s) : planet(Planet(x, y, z, 0.5, texture)) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->s = s;
	planet.light = true;
}

void EnergyBall::draw() {
	planet.draw();
//	glPushMatrix();
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glTranslated(x, y, z);
////	glRotated(-90, 1, 0, 0);
////	GLUquadricObj* esphere = gluNewQuadric();
////	gluQuadricTexture(esphere, true);
////	gluQuadricNormals(esphere, GLU_SMOOTH);
////	glEnable(GL_TEXTURE_2D);
////	glEnable(GL_CULL_FACE);
////	gluSphere(esphere, 0.5, 100, 100);
//	glutSolidSphere(0.5, 100, 100);
////	gluDeleteQuadric(esphere);
//	glPopMatrix();
}
