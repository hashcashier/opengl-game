/*
 * Animator.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Animator.h"

void Animator::animate(int value) {

	Character::setZ(Character::getZ() + 1);

	if(GameManager::getState() == GameManager::STATE_RUNNING)
		glutTimerFunc(16, animate, 16);
	glutPostRedisplay();
}
