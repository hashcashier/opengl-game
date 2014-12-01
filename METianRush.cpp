#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <glut.h>
using namespace std;

bool hasObstacle(int x, int z);


void color(int c){
	if(c==1){
		glColor3f(0.75,0.75,0.75);
	}
	if(c==2){
		glColor3f(1,0.4,1.017);
		glColor3f(0.6,0,0.29);
	}
	if(c==3){
		glColor3f(0.4,1,1);
		glColor3f(1,0.4,1.017);
	}
	if(c==0){
		glColor3f(0,0,0.4);
	}
}
void cube(int x, int y, int z){
	if(z%2==0)
		if(x%2==0)
			color(1);
		else
			color(2);
	else
		if(x%2==0)
			color(3);
		else
			color(0);
	glPushMatrix();
	glTranslated(x,y,z);
	glutSolidCube(1);
	glPopMatrix();
}

void drawWalkway(void) {
	for(int x=-11;x<12;x++)
		for(int z=29;z<120;z++)
		{
			cube(x, -10, z);
			if (hasObstacle(x,z)) {
				cube(x, -9, z);
				cube(x, -8, z);
				cube(x, -7, z);
				cube(x, -6, z);
			}
		}
}

void drawEndWall(void) {
	for (int x=-11;x<12;x++) {
		for (int y=-9;y<0;y++){
			cube(x,y,120);
		}
	}
	for (int y=0;y<=11;y++) {
		for (int x=y-11;x+y<12;x++) {
			cube(x,y,120);
		}
	}
}

void display(void)
{

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 0.1, 10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,0,0,0,1,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	drawWalkway();
	drawEndWall();

	glFlush();
	glutSwapBuffers();
}

bool hasObstacle(int x, int z) {
	return ((x+z)%17==0)&&(x%4==0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("METian Rush");
	glutDisplayFunc(display);
	//glutKeyboardFunc(MyKeyboard_shary);
	//glutSpecialFunc(MySpecialKeyboard_shary);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(1.0,1.0,1.0,0.0);
	glutMainLoop();
}
