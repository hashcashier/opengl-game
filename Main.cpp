// TryLoaded.cpp : Defines the entry point for the console application.
//


#include "platformIndependentHeader.h"
#include "input/Keyboard.h"
#include "display/display.h"
#include "display/light/Light.h"

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("Luminosity");
	glutDisplayFunc(Display::displayFunction);
	glutKeyboardFunc(Keyboard::keyboardFunction);
	glutSpecialFunc(Keyboard::keystrokeFunction);

//	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);

	Display::clear();

	Light::enableLighting();
//	Light::killAll();

	glutMainLoop();
}
