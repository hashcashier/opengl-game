/*
 * character.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "character.h"


void loadObj(string fname)
{
	FILE *fp;
	int read;
	GLfloat x, y, z;
	char ch;
	elephant=glGenLists(1);
	fp=fopen(fname.c_str(),"r");
	if (!fp)
	{
		printf("can't open file %s\n", fname.c_str());
		exit(1);
	}
	glPointSize(2.0);
	glNewList(elephant, GL_COMPILE);
	{
		glPushMatrix();
		glBegin(GL_POINTS);
		while(!(feof(fp)))
		{
			read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
			if(read==4&&ch=='v')
			{
				glVertex3f(x,y,z);
			}
		}
		glEnd();
	}
	glPopMatrix();
	glEndList();
	fclose(fp);
}

void drawCharacter()
{
	glPushMatrix();
	glTranslated(-1,-5.00,20);
	glColor3d(0.3,0.1,0.9);
	//glScalef(0.1,0.1,0.1);
	glScaled(0.2,0.2,0.2);
	glRotated(elephantrot,0,1,0);
	glCallList(elephant);
	glPopMatrix();
	/*elephantrot=elephantrot+0.6;
	if(elephantrot>360)elephantrot=elephantrot-360;*/
}


