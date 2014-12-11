/*
 * ObjectLoader.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "../../platformIndependentHeader.h"
using namespace std;

#ifndef OBJECTLOADER_H_
#define OBJECTLOADER_H_


class ObjectLoader {
public:
	static GLuint loadObject(string fname);
};


#endif /* OBJECTLOADER_H_ */
