/*
 * display.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "display.h"

void Display::displayFunction() {
	static Spotlight spotlight = Spotlight();
	Camera::setupCamera();
	if(!spotlight.isEnabled())
		spotlight.enable();

	GLfloat pos[] = {Character::getX(), Character::getY()+10, Character::getZ()-20, 1};
	spotlight.setPosition(pos);

	GLfloat dir[] = {0, -1, 2, 1};
	spotlight.setDirection(dir);

	spotlight.setIntensity(GameManager::getEnergy()/10.0);

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
