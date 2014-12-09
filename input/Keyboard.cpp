/*
 * Keyboard.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Keyboard.h"

void Keyboard::keyboardFunction(unsigned char c, int x, int y) {
	int state = GameManager::getState();
	switch(c) {
	case 's':
	case 'S':
		if(state == GameManager::STATE_STOPPED)
			GameManager::startGame();
		break;
	case 'r':
	case 'R':
		if(state == GameManager::STATE_PAUSED)
			GameManager::resumeGame();
		break;
	case 'p':
	case 'P':
		if(state == GameManager::STATE_RUNNING)
			GameManager::pauseGame();
		break;
	case 'n':
	case 'N':
		if(state == GameManager::STATE_OVER)
			GameManager::startGame();
		break;
	}
}

void Keyboard::keystrokeFunction(int key, int x, int y) {

}
