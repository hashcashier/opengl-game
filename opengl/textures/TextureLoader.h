/*
 * TextureLoader.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include "../../platformIndependentHeader.h"
using namespace std;

class TextureLoader {
public:
	static GLuint loadTexture(const char * filename, int width, int height,
			int wrap);
};

#endif /* TEXTURELOADER_H_ */
