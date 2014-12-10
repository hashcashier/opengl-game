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
				if(rand()%1000 == 0)
					energyBalls.push_back(Position(x, -9, z));
			}
	}

	glPushMatrix();
	glCallList(walkwayList);
	glPopMatrix();

	for(int i = 0; i < energyBalls.size(); i++)
		EnergyBall::draw(energyBalls[i].x, energyBalls[i].y, energyBalls[i].z, 1);
	return;
}

bool hasObstacle(int x, int z) {
	return ((x+z)%17==0)&&(x%4==0);
}

bool Walkway::nearEnergy(GLfloat x, GLfloat y, GLfloat z) {
	for(int i = 0; i < energyBalls.size(); i++) {
		GLfloat dx = energyBalls[i].x - x;
		GLfloat dy = energyBalls[i].y - y;
		GLfloat dz = energyBalls[i].z - z;
		if(dx*dx + dy*dy + dz*dz < 1)
			return true;
	}
	return false;
}

int Walkway::nearestEnergy(GLfloat x, GLfloat y, GLfloat z) {
	return false;
}

void Walkway::reset() {
	walkwayList = 0;
	energyBalls.clear();
}

void Walkway::removeBall(int i) {
	for(vector<Position>::iterator it = energyBalls.begin(); it != energyBalls.end(); it++, i--)
		if(!i) {
			energyBalls.erase(it);
			break;
		}
}
