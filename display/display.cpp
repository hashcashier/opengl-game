/*
 * display.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "display.h"

void Display::displayFunction() {
	Camera::setupCamera();

	drawWalkway();
	drawEndWall();

	Character::draw();

	HUD::draw();
	glFlush();
//	glutSwapBuffers();
}

void Display::clear() {
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glFlush();
}
