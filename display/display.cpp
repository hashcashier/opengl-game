/*
 * display.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "display.h"

void Display::displayFunction() {
	Camera::setupCamera();
	static Spotlight spotlight = Spotlight();
	spotlight.enable();

	GLfloat pos[] = {Character::getX(), Character::getY()+5, Character::getZ(), 1};
	spotlight.setPosition(pos);

	GLfloat dir[] = {Character::getX(), Character::getY(), Character::getZ(), 1};
	spotlight.setDirection(dir);

	drawWalkway();
	drawEndWall();

	Character::draw();


	HUD::draw();
	glFlush();
//	glutSwapBuffers();
}

void Display::clear() {
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glFlush();
}
