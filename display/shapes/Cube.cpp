/*
 * Cube.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Cube.h"

void Cube::color(int c) {
	if(c==1){
		glColor3f(0.75,0.75,0.75);
	}
	if(c==2){
		glColor3f(1,0.4,1.017);
		glColor3f(0.6,0,0.29);
	}
	if(c==3){
		glColor3f(0.4,1,1);
		glColor3f(1,0.4,1.017);
	}
	if(c==0){
		glColor3f(0,0,0.4);
	}
}

void Cube::draw(int x, int y, int z){
	if(z%2==0)
		if(x%2==0)
			color(1);
		else
			color(2);
	else
		if(x%2==0)
			color(3);
		else
			color(0);
	glPushMatrix();
	glTranslated(x,y,z);
	glutSolidCube(1);
	glPopMatrix();
}

void Cube::drawTextured(int x, int y, int z){
	static GLuint cubeTexture = TextureLoader::loadTexture("grassTexture.ppm", 444, 280, false);

	glPushMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glTranslated(x,y,z);
	GLUquadricObj* ecube = gluNewQuadric();
	gluQuadricTexture(ecube, true);
	gluQuadricNormals(ecube, GLU_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, cubeTexture);
	glEnable(GL_CULL_FACE);
	glutSolidCube(1);
//	gluSphere(ecube, 0.5, 100, 100);
	gluDeleteQuadric(ecube);

	glPopMatrix();
}
