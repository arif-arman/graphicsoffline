#include<GL/glut.h>
void drawChimney() {
	glPushMatrix(); {
		glColor3f(0.9, 0.9, 0.9);
		glPushMatrix(); {
			glScalef(4, 2, 0.2);
			glutSolidCube(20);
		}
		glPopMatrix();
		glColor3f(0.85, 0.85, 0.85);
		GLUquadric *quad;
		quad = gluNewQuadric();
		gluCylinder(quad, 10, 10, 35, 200, 200);
	}
	glPopMatrix();
}