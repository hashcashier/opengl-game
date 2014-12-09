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

	ostringstream oss;
	oss << GameManager::getScore();
	Camera::displayText(0, 560, "Score: " + oss.str());
	oss.str("");

	oss << GameManager::getEnergy();
	Camera::displayText(0, 540, "Energy: " + oss.str());
	oss.str("");

	oss << GameManager::getRound();
	Camera::displayText(0, 520, "Round " + oss.str());
	oss.str("");

	Camera::exit2DOverlay();
}
