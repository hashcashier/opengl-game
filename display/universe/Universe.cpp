/*
 * Universe.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "Universe.h"

void Universe::draw() {
	static GLuint decorTexture = PNGTextureLoader::loadTexture("bluespace.png");
	static Planet skysphere = Planet(0, 0, 0, 1500, PNGTextureLoader::loadTexture("bluespace.png"));
	glColor3f(1.0f, 1.0f, 1.0f);
	skysphere.draw();
	static vector<Planet> decor;
	if(decor.size() == 0) {
		for(int z = 0; z < Walkway::HIGH_LIMIT; z+= 50) {
			int random = rand();
//			int x = (random%2)*(Walkway::LEFT_LIMIT - 4) + ((random+1)%2)*(Walkway::RIGHT_LIMIT + 4);
			decor.push_back(Planet(Walkway::LEFT_LIMIT - 6, (random%100)*(-9.0/100), z, 5, decorTexture ));
			decor.push_back(Planet(Walkway::RIGHT_LIMIT + 6, (random%100)*(-9.0/100), z, 5, decorTexture ));
		}
	}
	glColor3f(1.0f, 1.0f, 1.0f);
	for(int i = 0; i < decor.size(); i++)
		decor[i].draw();

	static int var = Walkway::HIGH_LIMIT;
	static Planet end = Planet(0, 0, (GLfloat) var, 15, PNGTextureLoader::loadTexture("shroud.png"));
	end.draw();

	return;

}
