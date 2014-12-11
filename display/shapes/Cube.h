/*
 * Cube.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "../../platformIndependentHeader.h"
#include "../../opengl/textures/TextureLoader.h"
#include "../../opengl/textures/BMPTextureLoader.h"


using namespace std;

class Cube {
public:
	static void draw(int x, int y, int z);
	static void drawTextured(int x, int y, int z);
	static void color(int c);
};

#endif /* CUBE_H_ */
