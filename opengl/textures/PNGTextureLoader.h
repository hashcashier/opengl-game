/*
 * PNGTextureLoader.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#ifndef PNGTEXTURELOADER_H_
#define PNGTEXTURELOADER_H_

#include "../../platformIndependentHeader.h"
#include "PNG.h"
using namespace std;

class PNGTextureLoader {
public:
	static GLuint loadTexture(string fileName);
};

#endif /* PNGTEXTURELOADER_H_ */
