/*
 * GameManager.h
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

class GameManager {
	int GAME_STATE; // 0 = Main Menu, 1 = Paused, 2 = Running, 3 = Over
	int PLAYER_SCORE;
	int GAME_ROUND;
	int PLAYER_ENERGY;
public:
	GameManager();
	void startGame();
	void pauseGame();
	void endGame();
	int getState();
	void dissipateEnergy();
	void addEnergy(int amount);
	int getEnergy();
	void addScore(int amount);
	int getScore();
	void nextRound();
	int getRound();
};

#endif /* GAMEMANAGER_H_ */
