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
//	for(int i = 0; i < temp.size(); i++)
//		image[i] = temp[i];
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
