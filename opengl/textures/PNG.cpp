/*
 * PNG.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "PNG.h"

PNG::PNG(string fileName) {
	vector<unsigned char> temp;
	error = lodepng::decode(temp, width, height, fileName);
	//if there's an error, display it
	if (error)
		std::cout << "PNG Decoder Error " << error << ": "
				<< lodepng_error_text(error) << endl;
	image = new unsigned char[temp.size()];
//	for(int i = (temp.size()/4)-1, k = 0; i >= 0; i--, k++)
//		for(int j = 0; j < 4; j++)
//		image[4*k + j] = temp[4*i + j];
	memcpy(image, &temp[0], temp.size());
}

PNG::~PNG() {
	delete[] image;
}

bool PNG::isValid() {
	return !error;
}

int PNG::dimX() {
	return width;
}

int PNG::dimY() {
	return height;
}

const unsigned char* PNG::data() {
	return image;
}
