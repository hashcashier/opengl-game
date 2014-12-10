/*
 * HUD.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "HUD.h"

void HUD::drawStats() {
	ostringstream oss;
	oss << GameManager::getScore();
	Camera::displayText(0, 580, "Score: " + oss.str(), 0, 0, 100);
	oss.str("");

	oss << GameManager::getEnergy();
	Camera::displayText(0, 560, "Energy: " + oss.str(), 0, 0, 100);
	oss.str("");

	oss << GameManager::getRound();
	Camera::displayText(0, 540, "Round " + oss.str(), 0, 0, 100);
	oss.str("");
}

void HUD::draw() {
	Camera::enter2DOverlay();

	int state = GameManager::getState();
	if(state == GameManager::STATE_STOPPED) {
		Camera::displayText(0, 580, "Press S to Start!", 0, 0, 100);
		Camera::displayText(380, 300, "Luminosity", 100, 100, 100);
	} else if(state == GameManager::STATE_PAUSED) {
		drawStats();
		Camera::displayText(0, 520, "Press R to Resume.", 0, 100, 0);
	} else if(state == GameManager::STATE_RUNNING) {
		drawStats();
		Camera::displayText(0, 520, "Press P to Pause.", 100, 0, 0);
	} else if(state == GameManager::STATE_DONE) {
		drawStats();
		Camera::displayText(380, 300, "COMPLETE", 0, 255, 0);
		Camera::displayText(0, 500, "Press C for the next round.", 0, 0, 100);
	} else if(state == GameManager::STATE_OVER) {
		drawStats();
		Camera::displayText(380, 300, "GAMEOVER", 255, 0, 0);
		Camera::displayText(0, 500, "Press N for a New Game.", 0, 0, 100);
	}

	Camera::exit2DOverlay();
}
