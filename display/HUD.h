/*
 * HUD.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef HUD_H_
#define HUD_H_

#include "../platformIndependentHeader.h"
#include "camera/Camera.h"
#include "../game/GameManager.h"

using namespace std;

class HUD {
	static void drawStats();
public:
	static void draw();
};

#endif /* HUD_H_ */
