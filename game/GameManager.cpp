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

void GameManager::startGame() {
	GAME_STATE = 2;
}

void GameManager::pauseGame() {
	GAME_STATE = 1;
}

void GameManager::endGame() {
	GAME_STATE = 3;
}

int GameManager::getState() {
	return GAME_STATE;
}

void GameManager::dissipateEnergy() {
	// TODO: calculate new energy
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
