/*
 * BMPTextureLoader.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#ifndef BMPTEXTURELOADER_H_
#define BMPTEXTURELOADER_H_

#include "../platformIndependentHeader.h"
#include "BMP.h"
using namespace std;

class BMPTextureLoader {
public:
	GLuint loadTexture(string fileName);
};

#endif /* BMPTEXTURELOADER_H_ */
