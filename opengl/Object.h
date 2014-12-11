/*
 * Object.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "../platformIndependentHeader.h"
using namespace std;

class Object {
	vector<glm::vec3> vertices, normals;
	vector<glm::vec2> uvs;
public:
	Object(string fileName);
	void draw();
};

#endif /* OBJECT_H_ */
