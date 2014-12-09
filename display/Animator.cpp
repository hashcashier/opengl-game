/*
 * Animator.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Animator.h"

void Animator::animate(int value) {

	Character::moveForward(0.5);
//	GameManager::dissipateEnergy();

	if(GameManager::getState() == GameManager::STATE_RUNNING)
		glutTimerFunc(16, animate, 16);
	glutPostRedisplay();
}
