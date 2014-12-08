// TryLoaded.cpp : Defines the entry point for the console application.
//


#include "platformIndependentHeader.h"

#include "TextureBuilder.h"
using namespace std;

extern void displayFunction();

GLuint elephant;
float elephantrot;
char ch='1';
GLuint grassTexture;


//void reshape(int w,int h)
//{    
//	glViewport(0,0,w,h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
//	//glOrtho(-25,25,-2,2,0.1,100);	
//	glMatrixMode(GL_MODELVIEW);
//}

void color(int c){
	if(c==1){
		glColor3f(0.75,0.75,0.75);
	}
	if(c==2){
		glColor3f(1,0.4,1.017);
		glColor3f(0.6,0,0.29);
	}
	if(c==3){
		glColor3f(0.4,1,1);
		glColor3f(1,0.4,1.017);
	}
	if(c==0){
		glColor3f(0,0,0.4);
	}
}

void cube(int x, int y, int z){
	if(z%2==0)
		if(x%2==0)
			color(1);
		else
			color(2);
	else
		if(x%2==0)
			color(3);
		else
			color(0);
	glPushMatrix();
	glTranslated(x,y,z);
	glutSolidCube(1);
	glPopMatrix();
}

void cube_textured(int x, int y, int z){
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslated(x,y,z);
	static GLuint cubeTexture = LoadTexture("Earth.ppm", 720, 360, false);
	GLUquadricObj* ecube = gluNewQuadric();		
	gluQuadricTexture(ecube, true);
	gluQuadricNormals(ecube, GLU_SMOOTH);
	glEnable(GL_TEXTURE_2D);		
	glBindTexture(GL_TEXTURE_2D, cubeTexture);
	glEnable(GL_CULL_FACE);
	//glutSolidCube(1);
	gluSphere(ecube, 0.5, 100, 100);
	gluDeleteQuadric(ecube);
	glPopMatrix();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("METian Rush");
	glutDisplayFunc(displayFunction);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(MyKeyboard_shary);
	//glutSpecialFunc(MySpecialKeyboard_shary);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(1.0,1.0,1.0,0.0);
	glEnable(GL_TEXTURE_2D);

	loadObj("al.obj");
	glutMainLoop();
}
