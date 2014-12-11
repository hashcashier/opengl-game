/*
 * BMP.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "BMP.h"

BMP::BMP(string file) {
	image = bitmap_image(file);
}

BMP::~BMP() {
	// TODO Do what must be done
}

bool BMP::isValid() {
	if(!image)
		return false;
	return true;
}

int BMP::dimX() {
	return image.width();
}

int BMP::dimY() {
	return image.height();
}

const unsigned char* BMP::data() {
	return image.data();
}
