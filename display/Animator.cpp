/*
 * Animator.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Animator.h"

void Animator::animate(int val) {
	if(GameManager::getState() == GameManager::STATE_RUNNING)
		glutTimerFunc(25, animate, 25);

	Character::moveForward(0.25);

	if(Character::getZ() + 2 >= Walkway::HIGH_LIMIT)
		GameManager::finishGame();

	if(Walkway::nearEnergy(Character::getX(), Character::getY(), Character::getZ())) {
		int id = Walkway::nearestEnergy(Character::getX(), Character::getY(), Character::getZ());
		Walkway::removeBall(id);
		GameManager::addEnergy(100);
	}

	if(Walkway::nearCoin(Character::getX(), Character::getY(), Character::getZ())) {
		int id = Walkway::nearestCoin(Character::getX(), Character::getY(), Character::getZ());
		Walkway::removeCoin(id);
		GameManager::addScore(5);
	}

	GameManager::dissipateEnergy();

	glutPostRedisplay();
}
