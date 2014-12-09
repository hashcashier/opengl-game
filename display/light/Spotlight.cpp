/*
 * Spotlight.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Spotlight.h"

Spotlight::Spotlight() {
	number = Light::getAvailable();
	position[0] = position[1] = position[2] = 0;
	position[3] = 1;
	Light::reserveLight(number);
	setPosition(position);
}

void Spotlight::enable() {
	Light::enableLight(number);
	glLightf(Light::getLight(number), GL_SPOT_CUTOFF, 2.0);
	glLightf(Light::getLight(number), GL_SPOT_EXPONENT, 0.5);
}

void Spotlight::setPosition(GLfloat pos[]) {
	for(int i = 0; i < 4; i++)
		position[i] = pos[i];
	glLightfv(Light::getLight(number), GL_POSITION, position);
}

void Spotlight::disable() {
	Light::disableLight(number);
}
