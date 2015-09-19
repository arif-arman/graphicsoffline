#include<GL\glut.h>

void shutter() {
	glPushMatrix(); {
		glScalef(0.7, 1, 5);
		glRotatef(-30, 0, 0, 1);
		glColor3f(0.8, 0.8, 0.7);
		glBegin(GL_QUADS); {
			glVertex3f(0, 0, 10);
			glVertex3f(10, 0, 10);
			glVertex3f(10, 0, 0);
			glVertex3f(0, 0, 0);
		}
		glEnd();
	}
	glPopMatrix();
}

void drawScreen() {
	glPushMatrix(); {

		for (int k = 0; k < 10; k++) {
			glTranslatef(8, 0, 0);
			shutter();
		}
	}
	glPopMatrix();
}