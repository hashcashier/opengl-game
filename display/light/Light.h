/*
 * Light.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "../../platformIndependentHeader.h"
using namespace std;

class Light {
	static set<GLuint> enabledLights;
	static vector<GLuint> allLights;
public:
	static void enableLight(int i);
	static void disableLight(int i);
	static void enableLighting();
	static void disableLighting();
};

#endif /* LIGHT_H_ */
