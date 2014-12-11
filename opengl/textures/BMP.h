/*
 * BMP.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#ifndef BMP_H_
#define BMP_H_

#include "../../platformIndependentHeader.h"
#include "../../external/bitmap_image.hpp"

using namespace std;

class BMP {
	bitmap_image image;
public:
	BMP(string file);
	~BMP();
	bool isValid();
	int dimX();
	int dimY();
	const unsigned char* data();
};

#endif /* BMP_H_ */
