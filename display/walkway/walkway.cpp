/*
 * walkway.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "walkway.h"

void drawWalkway() {
	for(int x=-11;x<12;x++)
			for(int z=29;z<240;z++)
			{
				Cube::drawTextured(x, -10, z);
				if (hasObstacle(x,z)) {
					/*cube(x, -9, z);
					cube(x, -8, z);
					cube(x, -7, z);
					cube(x, -6, z);*/
					//drawObstacles(x,-9,z);
					//drawObstacles(x,-8,z);
					//drawObstacles(x,-7,z);
					drawObstacles(x,-6,z);
				}
			}
}

void drawEndWall() {
	for (int x=-11;x<12;x++) {
		for (int y=-9;y<0;y++){
			Cube::draw(x,y,240);
		}
	}
	for (int y=0;y<=11;y++) {
		for (int x=y-11;x+y<12;x++) {
			Cube::draw(x,y,240);
		}
	}
}


void drawObstacles(int x, int y, int z) {
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslated(x,y,z);//
	glRotated(-90,1,0,0);
	static GLuint eboxTexture = LoadTexture("stop13.ppm", 720, 360, true);
	GLUquadricObj* esphere = gluNewQuadric();
	gluQuadricTexture(esphere, true);
	gluQuadricNormals(esphere, GLU_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, eboxTexture);
	glEnable(GL_CULL_FACE);
	//gluCylinder(esphere,0.5, 0.5, 1,50,50);
	gluSphere(esphere, 0.5, 100, 100);
	gluDeleteQuadric(esphere);
	glPopMatrix();

}

bool hasObstacle(int x, int z) {
	return ((x+z)%17==0)&&(x%4==0);
}

