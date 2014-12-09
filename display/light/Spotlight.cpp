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
	enabled = false;
	intensity = 10;
}

void Spotlight::enable() {
	float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(Light::getLight(number), GL_AMBIENT, lightAmbient);	//Setup The Ambient Light

	glLightf(Light::getLight(number), GL_SPOT_EXPONENT, 2);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmbient);

	Light::enableLight(number);
	cerr << "Light " << number << " on" << endl;
	enabled = true;
}

bool Spotlight::isEnabled() {
	return enabled;
}

void Spotlight::setIntensity(GLfloat intens) {
	intensity = intens;
	glLightf(Light::getLight(number), GL_SPOT_CUTOFF, intensity);
}

void Spotlight::setPosition(GLfloat pos[]) {
	for(int i = 0; i < 4; i++)
		position[i] = pos[i];
	glLightfv(Light::getLight(number), GL_POSITION, position);
}

void Spotlight::setDirection(GLfloat pos[]) {
	for(int i = 0; i < 4; i++)
		direction[i] = pos[i];
	glLightfv(Light::getLight(number), GL_SPOT_DIRECTION, direction);
}

void Spotlight::disable() {
	Light::disableLight(number);
}
