/*
 * ObjectLoader.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "ObjectLoader.h"

GLuint ObjectLoader::loadObject(string fname) {
	cerr << "Loading: " << fname << endl;
	FILE *fp;
	int read;
	GLfloat x, y, z;
	GLuint object = glGenLists(1);
	char ch;
	fp = fopen(fname.c_str(), "r");
	if (!fp) {
		printf("Could not open object file %s. Terminating Application.\n", fname.c_str());
		exit(1);
	}
	glPointSize(2.0);
	glNewList(object, GL_COMPILE);

	glPushMatrix();
	glBegin(GL_POINTS);
	while (!(feof(fp))) {
		read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
		if (read == 4 && ch == 'v') {
			glVertex3f(x, y, z);
		}
	}
	glEnd();

	glPopMatrix();
	glEndList();
	fclose(fp);
	cerr << "ID: " << object << endl;
	return object;
}
