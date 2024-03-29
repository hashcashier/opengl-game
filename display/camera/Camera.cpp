/*
 * Camera.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Camera.h"

GLfloat Camera::cameraEyeInitial[3] = { 0, 0, 0 },
		Camera::cameraCenterInitial[3] = { 0, 0, 1 };

GLfloat Camera::cameraEye[3] = { 0, 0, 0 },
		Camera::cameraCenter[3] = { 0, 0, 1 },
		Camera::cameraUp[3] = { 0, 1, 0 };

void Camera::setupCamera() {
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 0.01, 1000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat lookAtZ = Character::getZ() - 30;
	GLfloat lookAtX = Character::getX();

	gluLookAt(	0,0,lookAtZ,
				0,-2,lookAtZ+30,
				0,1,0);

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

void Camera::enter2DOverlay() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();             //save
    glLoadIdentity();           //and clear

    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
}

void Camera::exit2DOverlay() {
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}


void Camera::displayText(int x, int y, string text, int r, int g, int b) {
	glPushMatrix();
    glColor3d(r, g, b);
    glRasterPos2i(x, y);
    void *font = GLUT_BITMAP_HELVETICA_18;
    for(int i = 0; i < text.length(); i++){
        glutBitmapCharacter(font, text[i]);
    }
    glPopMatrix();
}
