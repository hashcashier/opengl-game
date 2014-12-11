/*
 * display.h
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "../platformIndependentHeader.h"
#include "../game/character/character.h"
#include "camera/Camera.h"
#include "HUD.h"
#include "../opengl/objects/ObjectLoader.h"
#include "light/Spotlight.h"
#include "light/Light.h"
#include "universe/Universe.h"

using namespace std;

class Display {
public:
	static void displayFunction();
	static void clear();
};

#endif /* DISPLAY_H_ */
