/*
 * display.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "display.h"

void displayFunction() {
	static Character protagonist = Character(ObjectLoader::loadObject("al.obj"));
	Camera::setupCamera();

	drawWalkway();
	drawEndWall();

	protagonist.draw();

	HUD::draw();
	glFlush();
	glutSwapBuffers();
}

