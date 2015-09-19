#include<GL\glut.h>

void drawOrange() {
	glPushMatrix(); {
		glPushMatrix(); {
			glColor3f(1, 0.55, 0);
			glScalef(1.1, 1.1, 1);
			glutSolidSphere(20, 200, 200);
			
		}
		glPopMatrix();
		GLUquadric *quad;
		quad = gluNewQuadric();
		glPushMatrix(); {
			glColor3f(0.6, 0.1, 0.1);
			glTranslatef(0, 0, 20);
			gluCylinder(quad, 1, 0.5, 3, 200, 200);
		}
		glPopMatrix();
		
	}
	glPopMatrix();
}

void drawBowl() {
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		GLUquadric *quad;
		quad = gluNewQuadric();
		gluDisk(quad, 0, 8, 200, 200);
		for (float k = 8; k < 11; k += 0.5) {
			glTranslatef(0, 0, 0.8);
			glutSolidTorus(1, k, 200, 200);
		}
		for (float k = 11; k < 12; k += 0.5) {
			glTranslatef(0, 0, 0.8);
			glutSolidTorus(1, 11, 200, 200);
		}
	}
	glPopMatrix();
}