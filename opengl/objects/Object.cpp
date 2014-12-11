/*
 * Object.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "Object.h"

Object::Object(string fileName, GLdouble sx, GLdouble sy, GLdouble sz) {
	scaleX = sx;
	scaleY = sy;
	scaleZ = sz;
	rotX = rotY = rotZ = 0;
	object = 0;
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;

	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;
	fstream file(fileName.c_str(), fstream::in);
	if(!file.good())  {
		cerr << "Couldn't open object file " << fileName << endl;
	}
	string input;
	while(file >> input) {
		if(input == "v") {
			glm::vec3 vertex;
			file >> vertex.x >> vertex.y >> vertex.z;
			temp_vertices.push_back(vertex);
		} else if(input == "vt") {
			glm::vec2 uv;
			file >> uv.x >> uv.y;
			temp_uvs.push_back(uv);
		} else if(input == "vn") {
			glm::vec3 normal;
			file >> normal.x >> normal.y >> normal.z;
			temp_normals.push_back(normal);
		} else if(input == "f") {
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3], matches = 0;
			for(int i = 0; i < 3; i++) {
				file >> input;
				matches += sscanf(input.c_str(), "%d/%d/%d", &vertexIndex[i], &uvIndex[i], &normalIndex[i]);
			}
			if (matches != 9) {
				cerr << "Error in object file " + fileName << endl;
			} else {
				for(int i = 0; i < 3; i++)
					vertexIndices.push_back(vertexIndex[i]),
					uvIndices.push_back(uvIndex[i]),
					normalIndices.push_back(normalIndex[i]);
			}
		}
	}
	for(int i = 0; i < (int)vertexIndices.size(); i++)
		vertices.push_back( temp_vertices[ vertexIndices[i] - 1 ] ),
		uvs.push_back( temp_uvs[ uvIndices[i] - 1 ] ),
		normals.push_back( temp_normals[ normalIndices[i] - 1 ] );
}

void Object::draw() {
	if(!vertices.size()) {
		cerr << "Empty object!" << endl;
	} else if(vertices.size() != uvs.size() || uvs.size() != normals.size()){
		cerr << "Malformed arrays!" << endl;
	} else if(vertices.size()%3 != 0) {
		cerr << "Malformed object loaded." << endl;
	} else {
		glPushMatrix();
		glScaled(scaleX, scaleY, scaleZ);
		glBegin(GL_TRIANGLES);
		for(int i = 0; i < (int)vertices.size(); i++) {
			glNormal3f(normals[i].x, normals[i].y, normals[i].z);
			glTexCoord2d(uvs[i].x, uvs[i].y);
			glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
		}
		glEnd();
		glPopMatrix();
	}
//	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}

int Object::makeList() {
	if(object)
		return object;
	object = glGenLists(1);
	glNewList(object, GL_COMPILE);
	draw();
	glEndList();
	return object;
}

void Object::drawList(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(rotX,1,0,0);
	glRotated(rotY,0,1,0);
	glRotated(rotZ,0,0,1);
	glCallList(object);
	glPopMatrix();
}
