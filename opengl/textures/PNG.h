/*
 * PNG.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#ifndef PNG_H_
#define PNG_H_

#include "../../platformIndependentHeader.h"
#include "../../external/lodepng.h"
using namespace std;

class PNG {
	unsigned char *image;
	unsigned int width, height;
	unsigned int error;
public:
	PNG(string fileName);
	~PNG();
	bool isValid();
	int dimX();
	int dimY();
	const unsigned char* data();
};

#endif /* PNG_H_ */
