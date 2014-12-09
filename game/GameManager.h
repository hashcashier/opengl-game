/*
 * GameManager.h
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../platformIndependentHeader.h"
#include "../display/Animator.h"
using namespace std;

class GameManager {
	static int GAME_STATE; // 0 = Main Menu, 1 = Paused, 2 = Running, 3 = Over
	static int PLAYER_SCORE;
	static int GAME_ROUND;
	static int PLAYER_ENERGY;
public:
	static const int STATE_STOPPED, STATE_PAUSED, STATE_RUNNING, STATE_OVER;
	static void startGame();
	static void resumeGame();
	static void pauseGame();
	static void endGame();
	static int getState();
	static void dissipateEnergy();
	static void addEnergy(int amount);
	static int getEnergy();
	static void addScore(int amount);
	static int getScore();
	static void nextRound();
	static int getRound();
};

#endif /* GAMEMANAGER_H_ */
