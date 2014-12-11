/*
 * Object.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rami
 */

#include "Object.h"

Object::Object(string fileName) {
	// TODO Auto-generated constructor stub
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
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3], matches = 0;
			for(int i = 0; i < 3; i++) {
				string temp;
				file >> temp;
				matches += sscanf(temp.c_str(), "%d/%d/%d", &vertexIndex[i], &uvIndex[i], &normalIndex[i]);
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
		glBegin(GL_TRIANGLES);
		for(int i = 0; i < (int)vertices.size(); i++) {
			glNormal3f(normals[i].x, normals[i].y, normals[i].z);
			glTexCoord2d(uvs[i].x, uvs[i].y);
			glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
		}
		glEnd();
	}
//	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}
