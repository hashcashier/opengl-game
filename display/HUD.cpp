/*
 * HUD.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "HUD.h"

void HUD::draw() {
	Camera::enter2DOverlay();

	Camera::displayText(0, 580, "THIS IS A DEMO.");

	Camera::exit2DOverlay();
}
