/*
 * BMPTextureLoader.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "BMPTextureLoader.h"

GLuint BMPTextureLoader::loadTexture(string fileName) {
	BMP bitMap = BMP(fileName);

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

/*
	// Build Mipmaps (builds different versions of the picture for distances - looks better)
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bitMap.dimX(), bitMap.dimY(), GL_RGB, GL_UNSIGNED_BYTE, bitMap.data());

	// Lastly, we need to tell OpenGL the quality of our texture map.  GL_LINEAR_MIPMAP_LINEAR
	// is the smoothest.  GL_LINEAR_MIPMAP_NEAREST is faster than GL_LINEAR_MIPMAP_LINEAR,
	// but looks blochy and pixilated.  Good for slower computers though.

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);

	// The default GL_TEXTURE_WRAP_S and ""_WRAP_T property is GL_REPEAT.
	// We need to turn this to GL_CLAMP_TO_EDGE, otherwise it creates ugly seems
	// in our sky box.  GL_CLAMP_TO_EDGE does not repeat when bound to an object.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
*/

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitMap.dimX(), bitMap.dimY(), 0, GL_RGB, GL_UNSIGNED_BYTE, bitMap.data());


	return res;
}
