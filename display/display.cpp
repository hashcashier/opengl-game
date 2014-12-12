/*
 * display.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "display.h"

void Display::displayFunction() {
	static Spotlight spotlight = Spotlight();
	glLoadIdentity();
	Camera::setupCamera();

	if(GameManager::getState() != GameManager::STATE_STOPPED)
		Universe::draw();


	GLfloat pos[] = {Character::getX(), Character::getY()+10, Character::getZ()-50, 1};
//	GLfloat pos[] = {Character::getX(), Character::getY()+1, Character::getZ(), 1};
//	GLfloat pos[] = {Character::getX(), Character::getY()+1, Character::getZ()-10, 1};
	spotlight.setPosition(pos);
	GLfloat dir[] = {0, -1, 5, 1};
//	GLfloat dir[] = {0, 0, 1, 1};
//	GLfloat dir[] = {0, 0, 1, 1};
	spotlight.setDirection(dir);
	spotlight.setIntensity(GameManager::getEnergy()/60.0);

	if(!spotlight.isEnabled())
		spotlight.enable();

	glColor3f(1, 1, 1);


	if(GameManager::getState() != GameManager::STATE_STOPPED)
		Walkway::draw(),
		Character::draw();

	HUD::draw();
//	glFlush();
	glutSwapBuffers();
}

void Display::clear() {
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glFlush();
}
