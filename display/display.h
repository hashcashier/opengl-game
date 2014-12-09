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
#include "../opengl/ObjectLoader.h"

using namespace std;

extern void drawWalkway();
extern void drawEndWall();

class Display {
public:
	static void displayFunction();
	static void clear();
};

#endif /* DISPLAY_H_ */
