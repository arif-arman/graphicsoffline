#include<GL\glut.h>

void drawOrange() {
	glPushMatrix(); {
		glPushMatrix(); {
			glColor3f(1, 0.55, 0);
			glScalef(1.1, 1.1, 1);
			glutSolidSphere(4, 200, 200);
			
		}
		glPopMatrix();
		GLUquadric *quad;
		quad = gluNewQuadric();
		glPushMatrix(); {
			glColor3f(0.6, 0.1, 0.1);
			glTranslatef(0, 0, 4);
			gluCylinder(quad, 1, 0.5, 1, 200, 200);
		}
		glPopMatrix();
		
	}
	glPopMatrix();
}

void drawBowl() {
	glPushMatrix(); {
		glColor3f(0.4, 0.5, 0.4);
		GLUquadric *quad;
		quad = gluNewQuadric();
		glPushMatrix(); {
			gluDisk(quad, 0, 8, 200, 200);

		}
		glPopMatrix();
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