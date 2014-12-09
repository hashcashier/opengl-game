/*
 * Light.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Light.h"

set<int> Light::enabledLights;
GLuint lights[] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};
vector<GLuint> Light::allLights(lights, lights+8);

void Light::killAll() {
	GLfloat dummy[4] = { 0.0, 0.0, 0.0, 1.0 };
	for (int i = 0; i < allLights.size(); i++) {
		glLightfv(i, GL_AMBIENT, dummy);
		glLightfv(i, GL_DIFFUSE, dummy);
		glLightfv(i, GL_POSITION, dummy);
		glLightfv(i, GL_SPECULAR, dummy);
		glDisable(allLights[i]);
	}
	enabledLights.clear();
}

void Light::reserveLight(int i) {
	enabledLights.insert(i);
}

void Light::freeLight(int i) {
	enabledLights.erase(i);
}

void Light::enableLight(int i) {
	glEnable(allLights[i]);
	reserveLight(i);
}

void Light::disableLight(int i) {
	glDisable(allLights[i]);
}

void Light::enableLighting() {
	glEnable(GL_LIGHTING);
}

void Light::disableLighting() {
	glDisable(GL_LIGHTING);
}

bool Light::enabled(int i) {
	return enabledLights.count(i);
}

int Light::getAvailable() {
	for(int i = 0; i < allLights.size(); i++)
		if(enabledLights.count(i) == 0)
			return i;
	return -1;
}

GLuint Light::getLight(int i) {
	return allLights[i];
}
