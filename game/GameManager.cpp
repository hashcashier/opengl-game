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
const int GameManager::STATE_OVER = 3;


void GameManager::startGame() {
	cerr << "Game Started" << endl;
	GAME_ROUND++;
	PLAYER_SCORE = 0;
	PLAYER_ENERGY = 100;
	GAME_STATE = 2;
	glutPostRedisplay();
	Animator::animate(0);
}

void GameManager::resumeGame() {
	cerr << "Game Resumed" << endl;
	GAME_STATE = 2;
	glutPostRedisplay();
	Animator::animate(0);
}

void GameManager::pauseGame() {
	cerr << "Game Paused" << endl;
	GAME_STATE = 1;
	glutPostRedisplay();
}

void GameManager::endGame() {
	cerr << "Game End" << endl;
	GAME_STATE = 3;
	glutPostRedisplay();
}

int GameManager::getState() {
	return GAME_STATE;
}

void GameManager::dissipateEnergy() {
	if(PLAYER_ENERGY-- == 0)
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
