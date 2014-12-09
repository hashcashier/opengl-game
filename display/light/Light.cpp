/*
 * Light.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Light.h"

set<GLuint> Light::enabledLights;
GLuint lights[] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};
vector<GLuint> Light::allLights(lights, lights+8);

void Light::enableLight(int i) {
	glEnable(allLights[i]);
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

