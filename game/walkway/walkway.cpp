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
vector<EnergyBall> Walkway::energyBallsObj;
vector<Position> Walkway::coinDisks;

void Walkway::draw() {
//	static GLuint texture = BMPTextureLoader::loadTexture("box.bmp");
	static GLuint texture = PNGTextureLoader::loadTexture("space.png");
	if(walkwayList == 0) {
		walkwayList = glGenLists(1);
		cerr << "New list!" << endl;

		glNewList(walkwayList, GL_COMPILE);
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);

		glColor3f(1.0f, 1.0f, 1.0f);

		glColor3ub(50, 50, 100);
		glBindTexture(GL_TEXTURE_2D, texture);

		glBegin(GL_QUADS);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT_LIMIT-5,  -10, HIGH_LIMIT+10);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT_LIMIT-5,  -10, LOW_LIMIT-10);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT_LIMIT+5,  -10, LOW_LIMIT-10);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT_LIMIT+5,  -10, HIGH_LIMIT+10);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glEndList();
	}

	if(EnergyBall::texture == 0) {
		EnergyBall::texture = PNGTextureLoader::loadTexture("whitespace.png");
	}

	if(energyBalls.size() == 0) {
		for(int z = Walkway::LOW_LIMIT; z < Walkway::HIGH_LIMIT; z++)
			for(int x = Walkway::LEFT_LIMIT; x < Walkway::RIGHT_LIMIT; x++) {
				if(rand()%500 == 0)
					energyBalls.push_back(Position(x, -9, z)),
					energyBallsObj.push_back(EnergyBall(x, -9, z, 0.5));
			}
	if(coinDisks.size() == 0)
		for(int z = Walkway::LOW_LIMIT; z < Walkway::HIGH_LIMIT; z++)
			for(int x = Walkway::LEFT_LIMIT; x < Walkway::RIGHT_LIMIT; x++) {
				if(rand()%200 == 0)
					coinDisks.push_back(Position(x, -9, z));
			}
	}

	glCallList(walkwayList);
	glColor3ub(254, 254, 254);
	for(int i = 0; i < energyBalls.size(); i++)
		energyBallsObj[i].draw();
	glColor3f(1.0f, 1.0f, 1.0f);
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
	energyBallsObj.clear();
	coinDisks.clear();
}

template<typename T>
void Walkway::removeObject(int i, vector<T> &objects) {
	for(typename vector<T>::iterator it = objects.begin(); it != objects.end(); it++, i--)
		if(!i) {
			objects.erase(it);
			break;
		}
}

void Walkway::removeBall(int i) {
	removeObject(i, energyBalls);
	removeObject(i, energyBallsObj);
}

void Walkway::removeCoin(int i) {
	removeObject(i, coinDisks);
//	removeObject(i, coinDisksObj);
}
