// TryLoaded.cpp : Defines the entry point for the console application.
//


#include "platformIndependentHeader.h"

#include "TextureBuilder.h"
using namespace std;

GLuint elephant;
float elephantrot;
char ch='1';
GLuint grassTexture;

bool hasObstacle(int x, int z);

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

//void reshape(int w,int h)
//{    
//	glViewport(0,0,w,h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
//	//glOrtho(-25,25,-2,2,0.1,100);	
//	glMatrixMode(GL_MODELVIEW);
//}

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

void drawObstacles(int x, int y, int z) {
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslated(x,y,z);//
	glRotated(-90,1,0,0);
	static GLuint eboxTexture = LoadTexture("stop13.ppm", 720, 360, true);
	GLUquadricObj* esphere = gluNewQuadric();		
	gluQuadricTexture(esphere, true);
	gluQuadricNormals(esphere, GLU_SMOOTH);
	glEnable(GL_TEXTURE_2D);		
	glBindTexture(GL_TEXTURE_2D, eboxTexture);
	glEnable(GL_CULL_FACE);
	//gluCylinder(esphere,0.5, 0.5, 1,50,50);
	gluSphere(esphere, 0.5, 100, 100);
	gluDeleteQuadric(esphere);
	glPopMatrix();

}

void drawWalkway(void) {
	for(int x=-11;x<12;x++)
		for(int z=29;z<240;z++)
		{
			cube_textured(x, -10, z);
			if (hasObstacle(x,z)) {
				/*cube(x, -9, z);
				cube(x, -8, z);
				cube(x, -7, z);
				cube(x, -6, z);*/
				//drawObstacles(x,-9,z);
				//drawObstacles(x,-8,z);
				//drawObstacles(x,-7,z);
				drawObstacles(x,-6,z);
			}
		}
}

void drawEndWall(void) {
	for (int x=-11;x<12;x++) {
		for (int y=-9;y<0;y++){
			cube(x,y,240);
		}
	}
	for (int y=0;y<=11;y++) {
		for (int x=y-11;x+y<12;x++) {
			cube(x,y,240);
		}
	}
}

void display(void)
{

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 0.1, 10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,0,0,0,1,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	drawWalkway();
	drawEndWall();
	drawCharacter();

	glFlush();
	glutSwapBuffers();
}

bool hasObstacle(int x, int z) {
	return ((x+z)%17==0)&&(x%4==0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("METian Rush");
	glutDisplayFunc(display);
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
