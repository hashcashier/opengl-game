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
	static set<int> enabledLights;
	static vector<GLuint> allLights;
public:
	static void enableLight(int i);
	static void disableLight(int i);
	static void enableLighting();
	static void disableLighting();
	static bool enabled(int i);
	static int getAvailable();
	static GLuint getLight(int i);
	static void reserveLight(int i);
	static void freeLight(int i);
};

#endif /* LIGHT_H_ */
