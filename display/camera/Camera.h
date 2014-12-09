/*
 * Camera.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../../platformIndependentHeader.h"
using namespace std;

class Camera {
	static GLfloat cameraEyeInitial[3],
			cameraCenterInitial[3];

	static GLfloat cameraEye[3],
			cameraCenter[3],
			cameraUp[3];
public:
	static void setupCamera();
	static void enter2DOverlay();
	static void exit2DOverlay();
	static void displayText(int x, int y, string text, int r, int g, int b);
};

#endif /* CAMERA_H_ */
