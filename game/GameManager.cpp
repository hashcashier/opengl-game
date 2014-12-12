/*
 * GameManager.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "GameManager.h"

int GameManager::GAME_STATE = 0;
int GameManager::GAME_ROUND = 0;
int GameManager::PLAYER_SCORE = 0;
int GameManager::PLAYER_ENERGY = 0;

const int GameManager::STATE_STOPPED = 0;
const int GameManager::STATE_PAUSED = 1;
const int GameManager::STATE_RUNNING = 2;
const int GameManager::STATE_OVER = 4;
const int GameManager::STATE_DONE = 3;


void GameManager::startGame() {
	cerr << "Game Started" << endl;
	if(GAME_STATE == STATE_OVER || GAME_STATE == STATE_STOPPED)
		PLAYER_SCORE = GAME_ROUND = 0;
	GAME_ROUND++;
	PLAYER_ENERGY = 400;
	GAME_STATE = STATE_RUNNING;
	Character::resetPosition();
	Walkway::reset();
	glutPostRedisplay();
	Animator::animate(0);
}

void GameManager::resumeGame() {
	cerr << "Game Resumed" << endl;
	GAME_STATE = STATE_RUNNING;
	glutPostRedisplay();
	Animator::animate(0);
}

void GameManager::pauseGame() {
	cerr << "Game Paused" << endl;
	GAME_STATE = STATE_PAUSED;
	glutPostRedisplay();
}

void GameManager::finishGame() {
	cerr << "Round Finished" << endl;
	GAME_STATE = STATE_DONE;
	glutPostRedisplay();
}

void GameManager::endGame() {
	cerr << "Game End" << endl;
	GAME_STATE = STATE_OVER;
	glutPostRedisplay();
}

int GameManager::getState() {
	return GAME_STATE;
}

void GameManager::dissipateEnergy() {
	if(--PLAYER_ENERGY == 0)
		endGame();
}

void GameManager::addEnergy(int amount) {
	PLAYER_ENERGY += amount;
}

int GameManager::getEnergy() {
	return PLAYER_ENERGY;
}

void GameManager::addScore(int amount) {
	PLAYER_SCORE += amount;
}

int GameManager::getScore() {
	return PLAYER_SCORE;
}

void GameManager::nextRound() {
	GAME_ROUND++;
}

int GameManager::getRound() {
	return GAME_ROUND;
}
