/*
 * walkway.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "walkway.h"

const int Walkway::LEFT_LIMIT = -11;
const int Walkway::RIGHT_LIMIT = 12;
const int Walkway::LOW_LIMIT = 20;
const int Walkway::HIGH_LIMIT = 240;

GLuint grassTexture;
GLuint Walkway::walkwayList = 0;
vector<Position> Walkway::energyBalls;
vector<Position> Walkway::coinDisks;

void Walkway::draw() {
	if(walkwayList != 0) {
		glPushMatrix();
		glCallList(walkwayList);
		glPopMatrix();
	} else {
		walkwayList = glGenLists(1);
		cerr << "New list!" << endl;

		glNewList(walkwayList, GL_COMPILE);
		glPushMatrix();

		for (int x = Walkway::LEFT_LIMIT; x < Walkway::RIGHT_LIMIT; x++)
			for (int z = Walkway::LOW_LIMIT; z < Walkway::HIGH_LIMIT; z++)
				Cube::draw(x, -10, z);
		for (int x = Walkway::LEFT_LIMIT; x < Walkway::RIGHT_LIMIT; x++)
			for (int y = -9; y < 0; y++)
				Cube::draw(x, y, 240);
		for (int y = 0; y < Walkway::RIGHT_LIMIT; y++)
			for (int x = y - 11; x + y < 12; x++)
				Cube::draw(x, y, 240);

		glPopMatrix();
		glEndList();
	}

	if(energyBalls.size() == 0) {
		for(int z = Walkway::LOW_LIMIT; z < Walkway::HIGH_LIMIT; z++)
			for(int x = Walkway::LEFT_LIMIT; x < Walkway::RIGHT_LIMIT; x++) {
				if(rand()%500 == 0)
					energyBalls.push_back(Position(x, -9, z));
			}
	if(coinDisks.size() == 0)
		for(int z = Walkway::LOW_LIMIT; z < Walkway::HIGH_LIMIT; z++)
			for(int x = Walkway::LEFT_LIMIT; x < Walkway::RIGHT_LIMIT; x++) {
				if(rand()%200 == 0)
					coinDisks.push_back(Position(x, -9, z));
			}
	}

	glPushMatrix();
	glCallList(walkwayList);
	glPopMatrix();

	for(int i = 0; i < energyBalls.size(); i++)
		EnergyBall::draw(energyBalls[i].x, energyBalls[i].y, energyBalls[i].z, 1);
	for(int i = 0; i < coinDisks.size(); i++)
		Coin::draw(coinDisks[i].x, coinDisks[i].y, coinDisks[i].z, 1);
	return;
}

bool Walkway::nearObject(GLfloat x, GLfloat y, GLfloat z, vector<Position> &objects) {
	for(int i = 0; i < objects.size(); i++) {
		GLfloat dx = objects[i].x - x;
		GLfloat dy = objects[i].y - y;
		GLfloat dz = objects[i].z - z;
		if (dx * dx + dy * dy + dz * dz < 1)
			return true;
	}
	return false;
}

int Walkway::nearestObject(GLfloat x, GLfloat y, GLfloat z, vector<Position> &objects) {
	int res = 0;
	GLfloat dist = -1;
	for(int i = 0; i < objects.size(); i++) {
		GLfloat dx = objects[i].x - x;
		GLfloat dy = objects[i].y - y;
		GLfloat dz = objects[i].z - z;
		GLfloat dsqr = dx * dx + dy * dy + dz * dz;
		if (dist == -1 || dsqr < dist)
			dist = dsqr, res = i;
	}
	return res;
}

bool Walkway::nearEnergy(GLfloat x, GLfloat y, GLfloat z) {
	return nearObject(x, y, z, energyBalls);
}

bool Walkway::nearCoin(GLfloat x, GLfloat y, GLfloat z) {
	return nearObject(x, y, z, coinDisks);
}

int Walkway::nearestEnergy(GLfloat x, GLfloat y, GLfloat z) {
	return nearestObject(x, y, z, energyBalls);
}

int Walkway::nearestCoin(GLfloat x, GLfloat y, GLfloat z) {
	return nearestObject(x, y, z, coinDisks);
}

void Walkway::reset() {
	walkwayList = 0;
	energyBalls.clear();
	coinDisks.clear();
}

void Walkway::removeObject(int i, vector<Position> &objects) {
	for(vector<Position>::iterator it = objects.begin(); it != objects.end(); it++, i--)
		if(!i) {
			objects.erase(it);
			break;
		}
}

void Walkway::removeBall(int i) {
	removeObject(i, energyBalls);
}

void Walkway::removeCoin(int i) {
	removeObject(i, coinDisks);
}
