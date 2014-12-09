/*
 * Spotlight.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef SPOTLIGHT_H_
#define SPOTLIGHT_H_

#include "../../platformIndependentHeader.h"
#include "Light.h"
using namespace std;

class Spotlight {
	int number;
	GLfloat position[4], direction[4];
	GLfloat intensity;
	bool enabled;
public:
	Spotlight();
	void enable();
	void setPosition(GLfloat pos[]);
	void setDirection(GLfloat pos[]);
	void setIntensity(GLfloat intens);
	void disable();
	bool isEnabled();
};

#endif /* SPOTLIGHT_H_ */
