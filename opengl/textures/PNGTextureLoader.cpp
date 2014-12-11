/*
 * PNGTextureLoader.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "PNGTextureLoader.h"

GLuint PNGTextureLoader::loadTexture(string fileName) {
	PNG bitMap = PNG(fileName);

	if(!bitMap.isValid()) {
		cerr << "Could not load texture file: " << fileName << endl;
		return 0;
	}
	GLuint res = 0;
	// Generate a texture with the associative texture ID stored in the array
	glGenTextures(1, &res);
	cerr << "Texture " + fileName + ": " << res << endl;


	// Bind the texture to the texture arrays index and init the texture
	glBindTexture(GL_TEXTURE_2D, res);

	// This sets the alignment requirements for the start of each pixel row in memory.
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitMap.dimX(), bitMap.dimY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bitMap.data());

	return res;
}

