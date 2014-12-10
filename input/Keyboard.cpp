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
	case 'c':
	case 'C':
		if(state == GameManager::STATE_DONE)
			GameManager::startGame();
		break;
	}
}

void Keyboard::keystrokeFunction(int key, int x, int y) {
	int state = GameManager::getState();
	switch(key) {
	case(GLUT_KEY_LEFT):
		if(state == GameManager::STATE_RUNNING)
			Character::moveLeft(1);
		break;
	case(GLUT_KEY_RIGHT):
		if(state == GameManager::STATE_RUNNING)
			Character::moveRight(1);
		break;
	}
}
