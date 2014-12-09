// TryLoaded.cpp : Defines the entry point for the console application.
//


#include "platformIndependentHeader.h"

#include "opengl/ObjectLoader.h"

using namespace std;

extern void displayFunction();

//void reshape(int w,int h)
//{    
//	glViewport(0,0,w,h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
//	//glOrtho(-25,25,-2,2,0.1,100);	
//	glMatrixMode(GL_MODELVIEW);
//}

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
	glEnable(GL_TEXTURE_2D);
	glClearColor(1.0,1.0,1.0,0.0);
	glutMainLoop();
}
