/*
 * TextureLoader.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "TextureLoader.h"

GLuint TextureLoader::loadTexture(const char * filename, int width, int height,
		int wrap) {
	cerr << "Loading Texture: " << filename << endl;
	GLuint texture;
	char * data;
	FILE * file;

	// open texture data
	file = fopen(filename, "rb");
	if (file == NULL) {
		printf("Could not open texture file %s.\n", filename);
		return 0;
	}

	// allocate buffer
	data = (char*) malloc(width * height * 3);

	// read texture data
	fread(data, 1, width * height * 3, file);
	fclose(file);

	// allocate a texture name
	glGenTextures(1, &texture);

	// select our current texture
	glBindTexture(GL_TEXTURE_2D, texture);

	//glPixelStorei();

	// select modulate to mix texture with color for shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// when texture area is small, bilinear filter the closest MIP map
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_NEAREST);
	// when texture area is large, bilinear filter the first MIP map
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// if wrap is true, the texture wraps over at the edges (repeat)
	//       ... false, the texture ends at the edges (clamp)
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
			wrap ? GL_REPEAT : GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
			wrap ? GL_REPEAT : GL_CLAMP);

	// build our texture MIP maps
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE,
			data);

	// free buffer
	free(data);
	cerr << "Done, ID: " << texture << endl;
	return texture;
}
