/*
 * character.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "character.h"

//GLuint elephant = ObjectLoader::loadObject("al.obj");
GLuint elephant;
float elephantrot;
char ch='1';
GLuint grassTexture;

void drawCharacter()
{
	glPushMatrix();
	glTranslated(-1,-5.00,20);
	glColor3d(0.3,0.1,0.9);
	//glScalef(0.1,0.1,0.1);
	glScaled(0.2,0.2,0.2);
	glRotated(elephantrot,0,1,0);
	cerr << "Character: " << elephant << endl;
	glCallList(elephant);
	glPopMatrix();
	/*elephantrot=elephantrot+0.6;
	if(elephantrot>360)elephantrot=elephantrot-360;*/
}


