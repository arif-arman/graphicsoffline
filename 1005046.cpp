#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include "table.h"
#include "glass.h"
#include "pitcher.h"
#include "stove.h"
#include "kitchencabinet.h"
#include "kitchenCabinetUpper.h"
#include "chimney.h"
#include "chandelier.h"
#include "test.h"

using namespace std;

#include<GL/glut.h>

#define BLACK 0, 0, 0


//make a global variable -- for tracking the anglular position of camera
double cameraAngle;
double cameraRadius;
double cameraHeight;






void mergeCabinetStove() {
	drawKitchenCabinet(1);
	glPushMatrix(); {

		glScalef(2, 1, 2);
		drawStove();
	}
	glPopMatrix();
	drawKitchenCabinet(-1);
	glPushMatrix(); {
		glScalef(0.8, 0.5, 0.8);
		glTranslatef(30, -10, 75);
		drawKitchenCabinetUpper();
	}
	glPopMatrix();
	glPushMatrix(); {
		glScalef(0.8, 0.5, 0.8);
		glTranslatef(-110, -10, 75);
		drawKitchenCabinetUpper();
	}
	glPopMatrix();
	glPushMatrix(); {
		glScalef(0.6, 0.6, 1);
		glTranslatef(0, 0, 60);
		drawChimney();
	}
	glPopMatrix();
}

void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(BLACK, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	//instead of CONSTANT information, we will define a circular path.
	//	gluLookAt(-30,-30,50,	0,0,0,	0,0,1);

	gluLookAt(cameraRadius * cos(cameraAngle), cameraRadius * sin(cameraAngle), cameraHeight, 0, 0, 0, 0, 0, 1);
	//NOTE: the camera still CONSTANTLY looks at the center


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	// table
	//drawTable();

	// glass
	//drawGlass();

	// pitcher
	//drawPitcher();

	// kitchen cabinet
	//drawKitchenCabinet();
	//drawStove();
	//mergeCabinetStove();

	// kitchen cabinet upper
	//drawKitchenCabinetUpper();

	// chimney
	//drawChimney();

	// chandelier
	drawChandelier();

	// test
	//drawTest();

	/*
	glBegin(GL_LINES); {
	for (int i = 0; i <= n; i++) {

	glVertex3f(
	pointx + radius * cos(i*twoPi / n),
	pointy + radius * sin(i*twoPi / n),
	0);
	glVertex3f(
	pointx + radius * cos(i*twoPi / n),
	pointy + radius * sin(i*twoPi / n),
	20);
	}

	}
	glEnd();
	*/

	/*	//FORGET THE FIELD
	//an square field
	glColor3f(0.4, 1, 0.4);
	glBegin(GL_QUADS);{
	glVertex3f(-100,-100,0);
	glVertex3f(100,-100,0);
	glVertex3f(100,100,0);
	glVertex3f(-100,100,0);
	}glEnd();
	*/

	//some gridlines along the field
	int i;

	glColor3f(0.3, 0.3, 0.3);	//grey
	glBegin(GL_LINES); {
		for (i = -10; i <= 10; i++){

			if (i == 0)
				continue;	//SKIP the MAIN axes

			//lines parallel to Y-axis
			glVertex3f(i * 10, -100, 0);
			glVertex3f(i * 10, 100, 0);

			//lines parallel to X-axis
			glVertex3f(-100, i * 10, 0);
			glVertex3f(100, i * 10, 0);
		}
	}glEnd();

	// draw the two AXES
		//100% white
	glBegin(GL_LINES); {
		//Y axis
		glColor3f(0.2, 0.3, 0.4);
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0, 150, 0);

		//X axis
		glColor3f(0.6, 0.7, 0.8);

		glVertex3f(-150, 0, 0);
		glVertex3f(150, 0, 0);
	}glEnd();


	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera

	cameraAngle += 0.002;	// camera will rotate at 0.002 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN
}

void init(){
	//codes for initialization
	cameraAngle = 0;	//// init the cameraAngle
	cameraRadius = 150;
	cameraHeight = 50;

	//clear the screen
	glClearColor(BLACK, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70, 1, 0.1, 10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

void specialKeyListener(int key, int x, int y){
	switch (key){
	case GLUT_KEY_DOWN:		//down arrow key
		cameraRadius += 10;
		break;
	case GLUT_KEY_UP:		// up arrow key
		if (cameraRadius > 10)
			cameraRadius -= 10;
		break;

	case GLUT_KEY_RIGHT:
		cameraAngle += 0.4;
		break;
	case GLUT_KEY_LEFT:
		cameraAngle -= 0.4;
		break;
	case GLUT_KEY_PAGE_UP:
		cameraHeight += 10;
		break;
	case GLUT_KEY_PAGE_DOWN:
		cameraHeight -= 10;
		break;
	default:
		break;
	}
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA);	//Depth, Double buffer, RGB color

	glutCreateWindow("Table");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing


	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutSpecialFunc(specialKeyListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}