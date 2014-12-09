/*
 * display.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "display.h"

void Display::displayFunction() {
	static Spotlight spotlight = Spotlight();
	static Spotlight torch = Spotlight();
	glPushMatrix();
	Camera::setupCamera();

	GLfloat pos[] = {Character::getX(), Character::getY()+10, Character::getZ()-50, 1};
	spotlight.setPosition(pos);
	GLfloat dir[] = {0, -1, 5, 1};
	spotlight.setDirection(dir);
	spotlight.setIntensity(GameManager::getEnergy()/15.0);

	GLfloat tpos[] = {Character::getX(), Character::getY()+1, Character::getZ(), 1};
	torch.setPosition(tpos);
	GLfloat tdir[] = {0, 0, 1, 1};
	torch.setDirection(tdir);
	torch.setIntensity(100);

	if(!spotlight.isEnabled())
		spotlight.enable();
//	if(!torch.isEnabled())
//		torch.enable();

	drawWalkway();
	drawEndWall();

	Character::draw();
	glPopMatrix();


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
